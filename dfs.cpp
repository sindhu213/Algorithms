#include <iostream>
#include <list>
#include <vector>
#include <queue>

//Assuming 0-indexed
class Graph{
    private:
        std::vector<bool> visited;
        std::vector<std::list<int>> adj_list;

    public:
        Graph(int nVertices);
        void insertEdge(int from, int to);
        void breadthFirstSearch(int startingNode);
};

Graph::Graph(int nVertices){
    visited.resize(nVertices, false);
    adj_list.resize(nVertices);
}

void Graph::insertEdge(int from, int to){
    adj_list[from].push_back(to);
    adj_list[to].push_back(from);
}

void Graph::breadthFirstSearch(int startingNode){
    std::queue<int> queue;

    //initial configuration
    visited[startingNode] = true;
    queue.push(startingNode);

    while(!queue.empty()){
        int curr = queue.front();
        std::cout<<curr<<" ";
        queue.pop();

        for(auto const& adj: adj_list[curr]){
            if(!visited[adj]){
                visited[adj] = true;
                queue.push(adj);
            }
        }
    }
}

int main(){
    Graph g(5);
    g.insertEdge(0, 1);
    g.insertEdge(0, 4);
    g.insertEdge(1, 2);
    g.insertEdge(1, 4);
    g.insertEdge(2, 3);
    g.insertEdge(2, 4);
    g.insertEdge(3, 4);

    g.breadthFirstSearch(0);  //output: 0 1 4 3 2
    return 0;
}