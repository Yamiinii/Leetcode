class Solution {
public:
    void dfs(int node, vector<vector<int>>& adjList, int visited[]) {
        visited[node] = 1;
        for (auto it : adjList[node]) {
            if (!visited[it]) {
                dfs(it, adjList, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        int cnt = 0; // Initialize the count of provinces
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    // City i and city j are directly connected
                    adjList[i].push_back(j);
                }
            }
        }

        int visited[n];
        memset(visited, 0, sizeof(visited)); // Initialize visited array
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adjList, visited);
                cnt++;
            }
        }
        
        return cnt; // Return the count of provinces
    }
};
