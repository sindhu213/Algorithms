#include <iostream>
#include <vector>
#include <list>
#include <stack>

//
class Graph{
    private:
        std::vector<bool> visited;
        std::vector<std::list<int>> adj_list;

    public:
        Graph(int nVertices);
        void insertEdge(int from, int to);
        void depthFirstSearch(int startingNode);
};

Graph::Graph(int nVertices){
    visited.resize(nVertices, false);
    adj_list.resize(nVertices);
}

void Graph::insertEdge(int from, int to){
    adj_list[from].push_back(to);
    adj_list[to].push_back(from);
}

void Graph::depthFirstSearch(int startingNode){
    std::stack<int> stack;

    //initial configuration
    visited[startingNode] = true;
    stack.push(startingNode);

    while(!stack.empty()){
        int curr = stack.top();
        std::cout<<curr<< " ";
        stack.pop();

        for(auto const& adj: adj_list[curr]){
            if(!visited[adj]){
                visited[adj] = true;
                stack.push(adj);
            }
        }
    }
}

int main(){
    Graph g(5);
    g.insertEdge(1, 0);
    g.insertEdge(2, 1);
    g.insertEdge(3, 4);
    g.insertEdge(4, 0);

    g.depthFirstSearch(0); //output: 0 4 3 1 2 
    return 0;
}