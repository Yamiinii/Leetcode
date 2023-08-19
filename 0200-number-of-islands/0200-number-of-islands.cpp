class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0'; // Mark as visited
        
        dfs(i + 1, j, grid); // Down
        dfs(i - 1, j, grid); // Up
        dfs(i, j + 1, grid); // Right
        dfs(i, j - 1, grid); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        
        int cnt = 0; // Initialize the count of islands
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        
        return cnt; // Return the count of islands
    }
};
