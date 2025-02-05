
#include<iostream>
#include<vector>
#include<stack>
using namespace std;



class Graph{
    private:
     int V;  // for number of vertices
     vector<vector<int>> adj; // for adjacency list

    public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    void printGraph() {
    for (int i = 0; i < V; i++) {
        cout << i << ": ";  // Print the vertex number
        for (auto n : adj[i]) {
            cout << n << " ";  // Print each adjacent node followed by a space
        }
        cout << endl;  // Move to the next line after printing all adjacent nodes
    }
}


    // add vertices in graph
    void add(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected graph only
    }

    void breadth_first_search(int vertex){
       vector<bool> visited(V,false);
       stack<int> st;

       visited[vertex] = true;
       st.push(vertex);

       while(!st.empty()){
        int u = st.top(); st.pop();
        cout<<u<<" ";

        for(int n: adj[u]){
            if(!visited[n]){
                visited[n] = true;
                st.push(n);
            }
        }
       }
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
    g.add(2, 3);
    g.add(3, 4);

    // Display the graph
    g.printGraph();
    // g.breadth_first_search(0);

    return 0;
}