//1. implement Traversal for int data types on graphs.

//include header files
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<utility>
#include<forward_list>
#include<list> 
#include<algorithm>

using namespace std;



//BFS class
class Traversal{
    public:
        static void create_graph(const vector<pair<int,int>>& edges, unordered_map<int, vector<int>>& graph){
            for(auto edge : edges){
                //taking undirectional graph
                graph[edge.first].push_back(edge.second);
                graph[edge.second].push_back(edge.first);
            }
        }

        static vector<int> get_bfs_path(unordered_map<int, vector<int>>& graph, const int& start){
            vector<int> path;

            //assuming start is present in  the graph
            unordered_set<int> visited;
            list<int> container;

            container.push_back(start);
            visited.insert(start);

            while(!container.empty()){
                int node = container.front();
                container.pop_front();

                //add to the path after popping
                path.push_back(node);

                vector<int> neighbors = graph[node];

                //add to the container only if the neighbor is not visted
                for(const auto& neighbor : neighbors){
                    if(!visited.count(neighbor)){
                        container.push_back(neighbor);
                        //add to the visited when the node is inserted in the container
                        visited.insert(neighbor);
                    }
                }


            }

            return path;
        }



        static vector<int> get_dfs_path(unordered_map<int, vector<int>>& graph, const int& start){
            vector<int> path;

            //assuming start is present in  the graph
            unordered_set<int> visited;
            list<int> container;

            container.push_back(start);
            visited.insert(start);

            while(!container.empty()){
                int node = container.back();
                container.pop_back();

                //add to the path after popping
                path.push_back(node);

                vector<int> neighbors = graph[node];
                reverse(neighbors.begin(), neighbors.end());

                //add to the container only if the neighbor is not visted
                for(const auto& neighbor : neighbors){
                    if(!visited.count(neighbor)){
                        container.push_back(neighbor);
                        //add to the visited when the node is inserted in the container
                        visited.insert(neighbor);
                    }
                }


            }

            return path;
        }

};

//1,2,4,5,3,6,7 -- dfs

//1,3,7,6,2,5,4 -- dfs

//main function
int main(){
    vector<pair<int,int>> edges = {{1,2},{1,3},{2,4},{2,5},{3,6},{3,7}};
    unordered_map<int, vector<int>> graph;

    //create graph from edges
    Traversal::create_graph(edges, graph);

    //perform bfs traversal on graph starting from a node
    int start = 1;
    vector<int> bfs_path = Traversal::get_bfs_path(graph, start);
    for(auto node: bfs_path){
        cout<<node<<"->";
    }
    cout<<"\n";
    vector<int> dfs_path = Traversal::get_dfs_path(graph, start);
    for(auto node: dfs_path)
    cout<<node<<"->";
    

    return 0;
}

