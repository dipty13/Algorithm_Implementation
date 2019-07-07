#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<char,vector<char> > adjList;
    void addEdge(char node1, char node2, bool isBidirectional);
    void bfs(char src, char dest);
};

void Graph::addEdge(char node1, char node2, bool isBidirectional = true)
{
    adjList[node1].push_back(node2);
    if(isBidirectional)
        adjList[node2].push_back(node1);

}
void Graph::bfs(char src, char dest)
{
    queue<char> q;
    map<char, bool> visited;
    map<char, int> distance;
    map<char, char> parent;
    //parent[src] = -1;
    q.push(src);
    visited[src] = true;
    distance[src] = 0;
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
                distance[neighbor] = distance[node] + 1;
                parent[neighbor] = node;
            }
        }
    }
    cout << endl << " Shortest distance is: " << distance[dest] << endl;
    cout << "SHortest path is : " ;
    char temp = dest;
    while(temp != src){
        cout << temp << "<--";
        temp = parent[temp];
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
    g.bfs('A', 'I');

    return 0;
}
