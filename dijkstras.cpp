#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
};

void dijkstra(int V, const vector<vector<Edge>>& adj, int start) {
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : adj[u]) {
            int v = edge.to, weight = edge.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        cout << "Distance from " << start << " to " << i << " is: " << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<Edge>> adj(V);

    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    adj[0].push_back({2, 3});
    adj[2].push_back({0, 3});
    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});
    adj[1].push_back({3, 2});
    adj[3].push_back({1, 2});
    adj[2].push_back({3, 8});
    adj[3].push_back({2, 8});
    adj[3].push_back({4, 7});
    adj[4].push_back({3, 7});

    dijkstra(V, adj, 0);

    return 0;
}
