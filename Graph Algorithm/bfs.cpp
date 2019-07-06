#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<char,vector<char> > adjList;
    void addEdge(char node1, char node2, bool isBidirectional);
    void bfs(char src);
};

void Graph::addEdge(char node1, char node2, bool isBidirectional = true)
{
    adjList[node1].push_back(node2);
    if(isBidirectional)
        adjList[node2].push_back(node1);

}
void Graph::bfs(char src)
{
    queue<char> q;
    map<char, bool> visited;
    q.push(src);
    visited[src] = true;
    while(!q.empty())
    {
        char node = q.front();
        cout << node << ", ";
        q.pop();
        for(char neighbor: adjList[node])
        {
            if(!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
int main()
{
    Graph g;
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'D');
    g.addEdge('B', 'E');
    g.addEdge('B', 'F');
    g.addEdge('D', 'K');
    g.addEdge('F', 'I');
    g.addEdge('F', 'J');
    g.bfs('A');

    return 0;
}
