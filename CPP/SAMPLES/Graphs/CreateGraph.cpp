    #include <iostream>
    #include <vector>
    #include <unordered_map>
    // #include<bits/stdc++.h>
    #include <utility>
    using namespace std;
    

    

    template<typename T>
    class DirectedGraph{
        public:
            static void create_graph_from_edges(const vector<pair<T,T>>& edges, unordered_map<T, vector<T>>& graph){
                cout<<"Creating the graph...\n";
                for(auto edge: edges){
                    graph[edge.first].push_back(edge.second);
                }
            }

            static void print_graph(const unordered_map<T, vector<T>>& graph){
                cout<<"Printing the Graph...\n";
                for(auto node : graph){
                    cout<<node.first<<"---> ";
                    for(auto neighbor : node.second){
                        cout<<neighbor<<" ";
                    }
                    cout<<"\n";
                }
            }

    };


    int main(){

        vector<pair<int,int>> edges = {{1,2}, {2,3}, {3,4}, {4,5}, {5,1}};
        unordered_map<int, vector<int>> graph;
        DirectedGraph<int>::create_graph_from_edges(edges, graph);
        DirectedGraph<int>::print_graph(graph);


        vector<pair<char,char>> edges_char = {{'a','b'}, {'b','c'},{'c','d'},{'d','a'}};
        unordered_map<char, vector<char>> graph_char;
        DirectedGraph<char>::create_graph_from_edges(edges_char, graph_char);
        DirectedGraph<char>::print_graph(graph_char);
        

        return 0;
    }
