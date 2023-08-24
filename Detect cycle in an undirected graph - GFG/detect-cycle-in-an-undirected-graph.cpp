//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected gra

    bool dfs(vector<int> adj[], int visited[], int node, int parent) {
        visited[node] = 1;
        for (auto adjacent : adj[node]) {
            if (!visited[adjacent]) {
                if (dfs(adj, visited, adjacent, node))
                    return true;
            } else if (parent != adjacent) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle detected
    }

    bool isCycle(int V, vector<int> adj[]) {
        int visited[V];
        fill(visited, visited + V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(adj, visited, i, -1))
                    return true;
            }
        }

        return false;
    }
};


    

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends