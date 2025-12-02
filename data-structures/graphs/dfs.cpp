#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &order) {
    visited[u] = true;
    order.push_back(u);
    for (int v : graph[u]) { //VISIT ALL NEIGHBORS
        if (!visited[v]) {
            dfs(v, graph, visited, order);
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
    vector<bool> visited(V, false);
    vector<int> dfsOrder;
    dfs(0, adj, visited, dfsOrder);
    cout << "DFS Traversal: ";
    for (int u : dfsOrder) {
        cout << u << " ";
    }
    cout << endl;
    return 0;
}
