class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // If there is only one node, it's the root of the minimum height tree
        
        vector<unordered_set<int>> adj(n);
        vector<int> degree(n, 0);
        
        // Build the adjacency list and calculate the degree of each node
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].insert(v);
            adj[v].insert(u);
            degree[u]++;
            degree[v]++;
        }
        
        queue<int> leaves;
        // Add leaf nodes to the queue
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push(i);
            }
        }
        
        // Remove leaf nodes iteratively until one or two nodes remain
        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;
            
            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                
                for (int neighbor : adj[leaf]) {
                    adj[neighbor].erase(leaf); // Remove leaf from the neighbor's adjacency list
                    if (--degree[neighbor] == 1) {
                        leaves.push(neighbor); // If the neighbor becomes a leaf, add it to the queue
                    }
                }
            }
        }
        
        vector<int> minHeightTrees;
        while (!leaves.empty()) {
            minHeightTrees.push_back(leaves.front());
            leaves.pop();
        }
        
        return minHeightTrees;
    }
};
