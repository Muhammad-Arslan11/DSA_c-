
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

     adjList[u].push_back(v); // for directed graphs
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

    bool cycle_detection_using_dfs(int start){
        unordered_map<int ,bool> visited;
        unordered_map<

    }
};

int main(){

    return 0;
}