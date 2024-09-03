#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        // Directions for 4 possible moves (down, up, right, left)
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};

        // Min-heap priority queue (effort, x, y)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0); // (effort, x, y)

        while (!pq.empty()) {
            auto [currentEffort, xi, yi] = pq.top();
            pq.pop();
            
            // If we have reached the bottom-right cell, return the effort
            if (xi == n - 1 && yi == m - 1) {
                return currentEffort;
            }
            
            // Skip processing if the current path is not optimal
            if (currentEffort > dist[xi][yi]) continue;
            
            // Explore all 4 possible directions
            for (int i = 0; i < 4; ++i) {
                int nx = xi + x[i];
                int ny = yi + y[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    // Calculate the effort to move to the new cell
                    int newEffort = max(currentEffort, abs(grid[nx][ny] - grid[xi][yi]));

                    // Update distance if a better path is found
                    if (newEffort < dist[nx][ny]) {
                        dist[nx][ny] = newEffort;
                        pq.emplace(newEffort, nx, ny);
                    }
                }
            }
        }

        // If no path found, return -1 (shouldn't reach here for valid input)
        return -1;
    }
};
