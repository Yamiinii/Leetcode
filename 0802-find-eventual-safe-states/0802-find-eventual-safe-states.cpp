#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& path, int i, vector<int>& safeNodes) {
        vis[i] = 1;  // Mark node as visited
        path[i] = 1; // Mark node as part of the current recursion stack
        
        for (auto neighbor : adj[i]) {
            if (!vis[neighbor]) {
                if (dfs(adj, vis, path, neighbor, safeNodes)) {
                    // If neighbor is part of a cycle, current node is also part of a cycle
                    return true;
                }
            } else if (path[neighbor]) {
                // If neighbor is in the current recursion stack, a cycle is detected
                return true;
            }
        }
        
        path[i] = 0; // Unmark node as part of the current recursion stack
        safeNodes[i] = 1; // Mark node as safe
        return false; // No cycle found from this node
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0); // 0: not visited, 1: visited
        vector<int> path(V, 0); // 0: not in current path, 1: in current path
        vector<int> safeNodes(V, 0); // 0: not safe, 1: safe
        
        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(adj, vis, path, i, safeNodes);
            }
        }
        
        vector<int> result;
        for (int i = 0; i < V; ++i) {
            if (safeNodes[i]) {
                result.push_back(i);
            }
        }
        
        return result; 
    }
};
