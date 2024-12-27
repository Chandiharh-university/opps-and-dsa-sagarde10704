#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Graph {
    int V; // Number of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int v);
    void DFSUtil(int v, vector<bool> &visited);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (auto adjNode : adj[s]) {
            if (!visited[adjNode]) {
                visited[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
}

void Graph::DFSUtil(int v, vector<bool> &visited) {
    visited[v] = true;
    cout << v << " ";

    for (auto adjNode : adj[v]) {
        if (!visited[adjNode]) {
            DFSUtil(adjNode, visited);
        }
    }
}

void Graph::DFS(int v) {
    vector<bool> visited(V, false);
    DFSUtil(v, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Traversal starting from vertex 2:\n";
    g.BFS(2);

    cout << "\nDepth First Traversal starting from vertex 2:\n";
    g.DFS(2);

    return 0;
}
