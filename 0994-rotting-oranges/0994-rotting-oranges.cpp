class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        queue<pair<int, int>> q;
        int freshCount = 0;  // Count of fresh oranges
        
        // Push all initial rotten oranges into the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        // If there are no fresh oranges initially, return 0
        if (freshCount == 0) {
            return 0;
        }
        
        int xi[4] = {0, 0, 1, -1};
        int yi[4] = {1, -1, 0, 0};
        
        while (!q.empty()) {
            int size = q.size();
            bool changed = false;  // Flag to check if any oranges were rotten in this round
            
            for (int k = 0; k < size; k++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int x_n = x + xi[i];
                    int y_n = y + yi[i];
                    
                    // Check if the neighboring cell is within bounds and is a fresh orange
                    if (x_n >= 0 && x_n < n && y_n >= 0 && y_n < m && grid[x_n][y_n] == 1) {
                        grid[x_n][y_n] = 2;  // Mark the fresh orange as rotten
                        q.push({x_n, y_n});  // Push it to the queue for the next round
                        freshCount--;        // Decrement the count of fresh oranges
                        changed = true;      // Set changed flag to true
                    }
                }
            }
            
            if (changed) {
                time++;  // Increment time only if there were changes (oranges were rotten)
            }
        }
        
        // If there are still fresh oranges left, return -1
        if (freshCount > 0) {
            return -1;
        }
        
        return time;
    }
};
