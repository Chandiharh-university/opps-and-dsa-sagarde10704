#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int V, int E);
    void addEdge(int u, int v, int w);
    int find(vector<int> &parent, int i);
    void Union(vector<int> &parent, vector<int> &rank, int x, int y);
    void kruskalMST();
};

Graph::Graph(int V, int E) {
    this->V = V;
    this->E = E;
}

void Graph::addEdge(int u, int v, int w) {
    Edge edge = {u, v, w};
    edges.push_back(edge);
}

int Graph::find(vector<int> &parent, int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void Graph::Union(vector<int> &parent, vector<int> &rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

void Graph::kruskalMST() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; ++i)
        parent[i] = i;

    vector<Edge> result;
    for (Edge edge : edges) {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);

        if (x != y) {
            result.push_back(edge);
            Union(parent, rank, x, y);
        }
    }

    cout << "Edges in MST:\n";
    for (Edge edge : result)
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
}

int main() {
    int V = 4, E = 5;
    Graph g(V, E);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
