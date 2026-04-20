#include <bits/stdc++.h>
using namespace std;

// -----------------------------
// 🔴 DIJKSTRA ALGORITHM
// Time Complexity: O(E log V)
// -----------------------------

const int INF = 1e9;

// Function to run Dijkstra
void dijkstra(int n, vector<vector<pair<int, int>>> &adj, int src) {

    vector<int> dist(n, INF);

    // Min heap (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    // Print result
    cout << "Minimum cost from source:\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " -> " << dist[i] << endl;
    }
}

// -----------------------------
// MAIN (Testing)
// -----------------------------
int main() {

    int n = 5; // nodes

    // Adjacency list
    vector<vector<pair<int, int>>> adj(n);

    // (u -> v, cost)
    adj[0].push_back({1, 500});   // Food
    adj[0].push_back({2, 1000});  // Bills
    adj[1].push_back({3, 700});
    adj[2].push_back({3, 300});
    adj[3].push_back({4, 400});   // Goal

    dijkstra(n, adj, 0);

    return 0;
}