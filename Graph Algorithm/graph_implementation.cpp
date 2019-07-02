#include<bits/stdc++.h>
using namespace std;
class Graph
{
public:
    int vertex;
    vector<int> *adj;

    Graph(int vertex);
    void addEdge(int u, int v, bool isBidirectional);
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
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(3, 2);
    g.print();
    return 0;
}

