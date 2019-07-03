#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
    map<T, vector<T> > adj;
public:
    Graph()
    {
    }
    void addEdge(T u, T v, bool isBidirectional = true)
    {
        adj[u].push_back(v);
        if(isBidirectional)
        {
            adj[v].push_back(u);
        }
    }
    void print()
    {
        for(auto row: adj)
        {
            T key = row.first;
            cout << key << "->";
            for(T element: row.second)
            {
                cout << element << ",";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Siachen");
    g.addEdge("Delhi", "Banglor");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Amritsar", "Siachen");
    g.print();
    return 0;
}

