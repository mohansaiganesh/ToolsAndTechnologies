// Print the DFS path using recursion(no extra container)

//include modules
#include <iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//required classes and their functions
class Graph{
    public:
        static void create_graph(vector<pair<int,int>>& edges, unordered_map<int, vector<int>>& graph){
            for(auto edge : edges){
                graph[edge.first].push_back(edge.second);
                graph[edge.second].push_back(edge.first);
            }
            return;
        }
        static void dfs_path_recursive(unordered_map<int, vector<int>>& graph, int node, unordered_set<int>& visited, vector<int>& dfs_path){
            visited.insert(node);
            dfs_path.push_back(node);
            vector<int> neighbors = graph[node];
            for(auto neighbor : neighbors){
                if(!visited.count(neighbor)){
                    dfs_path_recursive(graph, neighbor, visited, dfs_path);
                }
            }
            return;
        }
};

//driver code
int main(){
    vector<int> path;
    vector<pair<int,int>> edges = {{1,2}, {1,3}, {2,4}, {2,5}, {3,6}, {3,7}};
    unordered_map<int,vector<int>> graph;
    Graph::create_graph(edges, graph);
    unordered_set<int> visited;
    Graph::dfs_path_recursive(graph, 1, visited, path);
    for(auto& x : path){
        cout<<x<<"->";
    }
    return 0;
}
