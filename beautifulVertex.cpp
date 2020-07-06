#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int dfs(int u, const vector<vector<int>> &adj, bool  *visited) {
    visited[u] = true;
    int result = 1;
    for (int v : adj[u]) {
        if (!visited[v]) 
            result += dfs(v, adj, visited);
        
    }
    return result;
}

int bfs(int s, const vector<vector<int>> &adj, bool *visited) {
    visited[s] = true;
    queue<int> Q;
    Q.push(s);
    int result = 1;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                result++;
                Q.push(v);
            }
        }
    }
    return result;
}

int beautifulVertex(int n, std::vector<std::vector<int>> edges)
{
    vector<vector<int>> adj(n + 1);
    bool *visited = new bool[n + 1];
        
    for (vector<int> x : edges) {
        adj[x[0]].push_back(x[1]);
    }

    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= n; i++) visited[i] = false;
        if (bfs(i, adj, visited) == n) return i;
    }
    return -1;
}

int main() {

    return 0;
}