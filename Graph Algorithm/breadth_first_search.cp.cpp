#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int vertex;
    vector<int> *adj;

    Graph(int vertex);
    void addEdge(int u, int v, bool isBidirectional);
    void bfs(int src);
    void print();
};

Graph::Graph(int vertex)
{
    this->vertex = vertex;
    this->adj = new vector<int>[vertex];
}

void Graph::addEdge(int u, int v, bool isBidirectional = true)
{
    adj[u].push_back(v);
    if(isBidirectional)
    {
        adj[v].push_back(u);
    }
}

void Graph::bfs(int src){
    queue<int> q;
    vector<bool> visited(vertex + 5, 0);

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        q.pop();
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

void Graph::print()
{
    for(int i = 0; i < vertex; i++)
    {
        cout << i << "-> ";
        for(int node: adj[i])//int j = 0; j < adj[i].size(); j++)
        {
            cout << node <<",";//adj[i][j] << ", ";
        }
        cout << endl;
    }
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 2);
    g.addEdge(2, 3);
    //g.print();
    g.bfs(0);
    return 0;
}

