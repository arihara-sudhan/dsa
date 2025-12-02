#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void iterativeDFS(int start, vector<vector<int>> &graph) {
    int V = graph.size();
    vector<bool> visited(V, false);
    stack<int> s;
    vector<int> dfsOrder;
    s.push(start);
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!visited[u]) {
            visited[u] = true;
            dfsOrder.push_back(u); 
            // Push Neighbors in REVERSE ORDER
            for (auto it = graph[u].rbegin(); it != graph[u].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);
                }
            }
        }
    }
    cout << "DFS Traversal (Iterative, same as recursive): ";
    for (int u : dfsOrder)
        cout << u << " ";
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 3};
    adj[1] = {3, 2};
    adj[2] = {};
    adj[3] = {2, 4};
    adj[4] = {};
    iterativeDFS(0, adj);
    return 0;
}
