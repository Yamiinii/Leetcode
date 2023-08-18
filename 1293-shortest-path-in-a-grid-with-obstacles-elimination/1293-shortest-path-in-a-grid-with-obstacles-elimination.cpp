class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> obs_seen(n, vector<int>(m, INT_MAX));
        obs_seen[0][0] = 0;
        int steps = 0;
        
        int row[4] = {0, 1, 0, -1};
        int col[4] = {1, 0, -1, 0};
        
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i++) {
                int x = Q.front().first, y = Q.front().second;
                Q.pop();
                
                if (x == n - 1 && y == m - 1)
                    return steps;
                
                for (int j = 0; j < 4; j++) {
                    int new_x = x + row[j], new_y = y + col[j];
                    
                    if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m) {
                        int obs = obs_seen[x][y] + grid[new_x][new_y];
                        
                        if (obs >= obs_seen[new_x][new_y] || obs > k)
                            continue;
                        
                        obs_seen[new_x][new_y] = obs;
                        Q.push({new_x, new_y});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
