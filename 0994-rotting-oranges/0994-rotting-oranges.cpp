class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total = 0;
        int rotten = 0;
        int time = 0;
        queue<pair<int, int>> q;
        
        // Calculate total oranges and push all initial rotten oranges into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    total++;
                }
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    rotten++; // Increment rotten count for initial rotten oranges
                }
            }
        }
        
        // Directions for up, down, left, right movements
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        
        while (!q.empty()) {
            int k = q.size(); // Number of oranges in the current level of BFS
            
            while (k--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for (int idx = 0; idx < 4; idx++) {
                    int ni = i + x[idx];
                    int nj = j + y[idx];
                    
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] != 1) continue;
                    
                    grid[ni][nj] = 2;
                    q.push({ni, nj});
                    rotten++; // Increment rotten count for newly affected oranges
                }
            }
            
            if (!q.empty()) {
                time++; // Increment time after processing each level of BFS
            }
        }
        
        return total == rotten ? time : -1; // Return time taken or -1 if not all oranges are rotten
    }
};
