class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int m, int n, int i, int j) {
        // Mark the current cell as visited
        visited[i][j] = true;
        
        // Direction vectors for moving in 4 directions (right, left, down, up)
        int x[] = {1, -1, 0, 0};
        int y[] = {0, 0, 1, -1};
        
        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            int xi = i + x[k];
            int yi = j + y[k];
            
            // Check if the new cell is within bounds and not visited and is part of an island
            if (xi >= 0 && xi < m && yi >= 0 && yi < n && !visited[xi][yi] && grid[xi][yi] == '1') {
                dfs(grid, visited, m, n, xi, yi);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        
        // Initialize the visited grid
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // Iterate through all cells in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the cell is land and not visited, it is a new island
                if (grid[i][j] == '1' && !visited[i][j]) {
                    cnt++;
                    dfs(grid, visited, m, n, i, j);
                }
            }
        }
        
        return cnt;
    }
};
