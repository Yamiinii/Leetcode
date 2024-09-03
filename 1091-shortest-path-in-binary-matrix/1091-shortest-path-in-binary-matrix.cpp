class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Check for edge cases
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // Directions for 8 possible moves (including diagonals)
        int x[8] = {1, -1, 0, 0, 1, -1, 1, -1};
        int y[8] = {0, 0, 1, -1, 1, -1, -1, 1};

        // Initialize the distance matrix and the queue for BFS
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1; // Start from (0,0) and count it as part of the path
        queue<pair<int, int>> q;
        q.push({0, 0});

        // Perform BFS
        while (!q.empty()) {
            auto [xi, yi] = q.front();
            q.pop();

            // If we have reached the bottom-right cell, return the distance
            if (xi == n - 1 && yi == n - 1) {
                return dist[xi][yi];
            }

            // Explore all 8 possible directions
            for (int i = 0; i < 8; ++i) {
                int nx = xi + x[i];
                int ny = yi + y[i];

                // Check if the new cell is within bounds and is a valid move
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    // Check if we found a shorter path to (nx, ny)
                    if (dist[nx][ny] > dist[xi][yi] + 1) {
                        dist[nx][ny] = dist[xi][yi] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // If we exit the loop without having reached (n-1, n-1), return -1
        return -1;
    }
};
