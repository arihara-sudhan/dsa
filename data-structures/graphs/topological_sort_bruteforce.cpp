#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> computeInDegree(int V, vector<vector<int>> &graph) {
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : graph[u]) {
            indegree[v]++;
        }
    }
    return indegree;
}

void removeVertex(int vertex, vector<vector<int>> &graph) {
    int V = graph.size();
    graph[vertex].clear(); // remove OUTGOING edges of this vertex
    // remove INCOMING edges
    for (int u = 0; u < V; u++) {
        graph[u].erase(
            remove(graph[u].begin(), graph[u].end(), vertex),
            graph[u].end()
        );
    }
}

vector<int> topologicallySort(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<int> topoOrder;

    while (true) {
        vector<int> indegree = computeInDegree(V, graph);
        int vertex = -1;
        for (int v = 0; v < V; v++) {
            if (indegree[v] == 0) {
                vertex = v;
                break;
            }
        }

        if (vertex == -1) break;   // No indegree 0 → done or cycle
        topoOrder.push_back(vertex);
        removeVertex(vertex, graph);
    }

    if (topoOrder.size() != V) {
        cout << "CYCLE FOUND | INCOMPLETE SORTING\n";
    } else {
        for (int v : topoOrder)
            cout << v + 1 << " ";
        cout << endl;
    }

    return topoOrder;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 3};
    adj[1] = {3, 2};
    adj[2] = {};
    adj[3] = {2, 4};
    adj[4] = {};
    topologicallySort(adj);
    return 0;
}
