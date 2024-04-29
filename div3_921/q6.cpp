#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Edge {
    int u, v, weight;

    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}

    // Comparator for sorting edges by weight
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

vector<Edge> edges;
vector<vector<pair<int, int>>> adj; // Adjacency list representation of the graph
vector<bool> visited;

// Depth-First Search to find a cycle
bool dfs(int u, int parent, const int start, const int min_weight, vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    for (auto& edge : adj[u]) {
        int v = edge.first;
        
        int weight = edge.second;

        if (!visited[v]) {
            if (dfs(v, u, start, min_weight, path)) {
                return true;
            }
        } else if (v != parent && weight == min_weight && u != start) {
            path.push_back(v);
            return true;
        }
    }

    path.pop_back();
    return false;
}

// Function to find a simple cycle with the minimum weight edge
vector<int> findSimpleCycle(int n) {
    visited.assign(n + 1, false);

    for (const auto& edge : edges) {
        int u = edge.u, v = edge.v;
        if (!visited[u]) {
            vector<int> path;
            if (dfs(u, -1, u, edge.weight, path)) {
                return path;
            }
        }
    }

    return {}; // If no cycle found
}

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n, m;
        cin >> n >> m; // Number of vertices and edges

        adj.resize(n + 1);
        edges.reserve(m);

        for (int i = 0; i < m; ++i) {
            int u, v, weight;
            cin >> u >> v >> weight;
            edges.emplace_back(u, v, weight);
            adj[u].emplace_back(v, weight);
            adj[v].emplace_back(u, weight);
        }

        sort(edges.begin(), edges.end());

        vector<int> cycle = findSimpleCycle(n);
        if (!cycle.empty()) {
            cout << edges[0].weight << " " << cycle.size()-1 << endl; // Output b and k
            for (int i=0; i< cycle.size()-1;i++) {
                cout << cycle[i] << " "; // Output vertices of the cycle
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }

        // Clear data structures for the next test case
        edges.clear();
        adj.clear();
        visited.clear();
    }

    return 0;
}

