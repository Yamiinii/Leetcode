class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1; // Start or end cell is blocked
        }
        
        int x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int y[8] = {1, 0, -1, 1, -1, 1, 0, -1};
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark the start cell as visited
        
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            if (i == n - 1 && j == n - 1) {
                return grid[i][j]; // Reached the end cell
            }
            
            for (int k = 0; k < 8; ++k) {
                int ni = i + x[k];
                int nj = j + y[k];
                
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0) {
                    q.push({ni, nj});
                    grid[ni][nj] = grid[i][j] + 1; // Mark cell as visited and update distance
                }
            }
        }
        
        return -1; // No clear path found
    }
};
