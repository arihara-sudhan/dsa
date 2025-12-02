#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<vector<int>>& graph) {
    int V = graph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; //BFS ORDER
        // NEIGHBOURS BEING PUSHED
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 3};
    adj[1] = {3, 2};
    adj[2] = {};
    adj[3] = {2, 4};
    adj[4] = {};
    bfs(0, adj);  // START FROM NODE 0
}
