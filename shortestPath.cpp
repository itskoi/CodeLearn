#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

std::vector<int> shortestPath(int n, std::vector<std::vector<int>> edges)
{
    queue<int> qu;
    vector<vector<int>> adj(n + 1);
    bool *visited = new bool[n + 1];
    vector<int> result(n + 1, 0);

    memset(visited, false, sizeof visited);

    for (vector<int> x : edges) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    result[1] = 0;
    qu.push(1);
    visited[1] = true;
    while(!qu.empty()) {
        int u = qu.front(); qu.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                result[v] = result[u] + 1;
                qu.push(v);
            }
        }
    }
    result.erase(result.begin());
    return result;
}

int main() {
    vector<int> a = shortestPath(3,{{1,2},{2,3}, {1,3}});
    for (int x : a) cout << x << " "; 
    return 0;
}