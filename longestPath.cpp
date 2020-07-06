#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

void dfs(int u, int s, int t, const vector<vector<int>> &adj, bool *&visited, vector<int> &result) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (v == s) continue;
        if (v == t) {
            result[v] = max(result[v], result[u] + 1);
        } else {
            if (!visited[v]) {
                result[v] = result[u] + 1;
                dfs(v, s, t, adj, visited, result);
            } else {
                if (result[v] < result[u] + 1) {
                    result[v] = result[u] + 1;
                    dfs(v, s, t, adj, visited, result);
                }
            }
        }
    }
}

int longestPath(int n, std::vector<std::vector<int>> edges, int u, int v)
{
    vector<vector<int>> adj(n + 1);
    bool *visited = new bool[n + 1];
    vector<int> result(n + 1, -1);

    for (int i = 1; i <= n; i++) visited[i] = false;
    queue<int> qu;
    qu.push(u);
    visited[u] = true;
    result[u] = 0;
    for (vector<int> x : edges) {
        adj[x[0]].push_back(x[1]);
    }

    dfs(u, u, v, adj, visited, result);

    return result[v];
}

int main() {
    cout << longestPath(3, {{1, 2}, {2, 3}, {1, 3}}, 1, 3);
    return 0;
}