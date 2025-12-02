#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> indegree(V, 0);
    // Compute InDegree only ONCE
    for (int u = 0; u < V; u++) {
        for (int v : graph[u])
            indegree[v]++;
    }
    queue<int> q;
    // Push all InDegree 0 Nodes
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        // Remove outgoing edges
        for (int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    if (topo.size() != V)
        cout << "Cycle detected\n";
    return topo;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 3};
    adj[1] = {3, 2};
    adj[2] = {};
    adj[3] = {2, 4};
    adj[4] = {};
    vector<int> order = topologicalSort(adj);
    for (int v : order) cout << v + 1 << " ";
    cout << endl;
}
