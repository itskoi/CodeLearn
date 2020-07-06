#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>

using namespace std;

bool dfs(int u, int des, bool* visited, const vector<vector<int>> &adj) {
    if (u == des) return true;
    if (visited[u]) return false;
    visited[u] = true;
    bool res = false;
    for (int v : adj[u]) {
        res |= dfs(v, des, visited, adj);
    }
    return res;
}

bool findPath(int n, std::vector<std::vector<int>> edges, int u, int v)
{
    vector<vector<int>> adj(n + 1);
    for (vector<int> x : edges) {
        adj[x[0]].push_back(x[1]);
    }
    bool *visited = new bool[n + 1];
    memset(visited, false, sizeof visited);

    return dfs(u, v, visited, adj);
}

int main() {
    cout << findPath(3, {{1, 2}, {2, 3}}, 1, 3);
    return 0;
}