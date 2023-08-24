//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
     bool detect(vector<int> adj[], int visited[], int node) {
    visited[node] = 1;
    queue<pair<int, int>> q;
    q.push({node, -1});
    while (!q.empty()) {
      int currNode = q.front().first;
      int parent = q.front().second;
      q.pop();
      for (auto adjacent : adj[currNode]) {
        if (!visited[adjacent]) {
          q.push({adjacent, currNode});
          visited[adjacent] = 1;
        } else if (parent != adjacent) {
          return true; // Cycle detected
        }
      }
    }
    return false; // No cycle detected
  }
  bool isCycle(int V, vector<int> adj[]) {
    // Code here
    int visited[V]={0};
    for (int i = 0; i < V; i++) {
      if (!visited[i] && detect(adj, visited, i))
        return true;
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