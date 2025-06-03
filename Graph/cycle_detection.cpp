
// cycle detection using bfs
#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
using namespace std;

class Graph{
    private:
    int V;  // for number of vertices
    vector<vector<int>> adjList; // for adjacency list

    public:
    Graph(int vertices) : V(vertices), adjList(vertices){}

    // add
    void addAdj(int u, int v){

     adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void print(){
        for(int i =0; i<adjList.size(); i++){
              cout << i << ": ";
            for(auto n : adjList[i]){
               cout << n << " ";
            }
             cout<<endl;
        }
    }

      bool isCyclePresent(int start) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);  // To keep track of the parent of each node
        stack<int> bucket; // bucket to keep track of elements\

        bucket.push(start);
        visited[start] = true;

        while (!bucket.empty()) {
            int elem = bucket.top();
            bucket.pop();

            for (int n : adjList[elem]) {
                if (!visited[n]) {
                    visited[n] = true;
                    parent[n] = elem;  // Mark elem as the parent of n
                    bucket.push(n);
                } else if (parent[elem] != n) {  
                    // If visited and not the parent, a cycle is detected
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
   Graph g(10);

   g.addAdj(1,2);
   g.addAdj(2,3);
   g.addAdj(4,5);
   g.addAdj(5,6);
   g.addAdj(5,7);
   g.addAdj(6,8);
   g.addAdj(8,7);
   g.addAdj(8,9);

   g.print();
   
    return 0;
}