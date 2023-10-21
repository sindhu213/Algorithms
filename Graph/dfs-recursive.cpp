#include <iostream>
#include <list>
#include <vector>

//Assuming 0-based indexing and no repetition
class Graph{
    private:
        std::vector<std::list<int>> adj_list;
        std::vector<bool> visited;

    public:
        Graph(int nVertices);
        void insertEdge(int from, int to);
        void depthFirstSearch(int source);
};

Graph::Graph(int nVertices){
    adj_list.resize(nVertices);
    visited.resize(nVertices, false);
}

void Graph::insertEdge(int from, int to){
    adj_list[from].push_back(to);
    adj_list[to].push_back(from);
}

void Graph::depthFirstSearch(int source){
    visited[source] = true;
    std::cout<<source<<" ";

    for(auto const& adj: adj_list[source]){
        if(!visited[adj]){
            depthFirstSearch(adj);
        }
    }
}

int main(){
    Graph g(5);
    g.insertEdge(0,1);
    g.insertEdge(0,2);
    g.insertEdge(1,3);
    g.insertEdge(1,4);
    g.insertEdge(3,4);

    g.depthFirstSearch(2);  //output: 2 0 1 3 4
    return 0;
}