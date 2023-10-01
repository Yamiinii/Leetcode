//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

public:
    bool dfs(vector<int> adj[], vector<int>& visited, vector<int>& pathVisit, int node) {
        visited[node] = 1;
        pathVisit[node] = 1;
        for (auto it : adj[node]) {
            if (visited[it] != 1) {
                if (dfs(adj, visited, pathVisit, it) == true)
                    return true;
            } else if (pathVisit[it])
                return true;
        }
        pathVisit[node]=0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, -1);
        vector<int> pathVisit(V, -1);
        for (int i = 0; i < V; i++) {
            if (dfs(adj, visited, pathVisit, i) == true)
                return true;
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends