
#include<iostream>
#include<vector>
using namespace std;

class Graph{
    private:
     int V;  // for number of vertices
     vector<vector<int>> adj; // for adjacency list

    public:
    Graph(int vertices) : V(vertices), adj(vertices) {}
    // print
    void printGraph(){
        for(int i=0; i<V; i++){
            for(auto n : adj[i]){
              cout<< i<< ": ";
            }
            cout<<endl;
        }
    }

    // add vertices in graph
    void add(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph only
    }
};

int main(){
    int vertices = 5;

   Graph g(vertices);
   
    // Adding edges
    g.add(0, 1);
    g.add(0, 4);
    g.add(1, 2);
    g.add(1, 3);
    g.add(1, 4);
    g.add(2, 3);
    g.add(3, 4);

    // Display the graph
    g.printGraph();

    return 0;
}