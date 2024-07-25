class Solution {
public:
    void dfs(vector<vector<int>>& v, vector<int>& visited, int i) {
        visited[i] = 1;
        for (auto it : v[i]) {
            if (!visited[it]) {
                dfs(v, visited, it);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> v(n);  // Adjacency list for graph
        
        // Build adjacency list from isConnected matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        
        vector<int> visited(n, 0);
        int cnt = 0;  // Counter for connected components
        
        // Perform DFS to find connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(v, visited, i);
            }
        }
        
        return cnt;
    }
};
