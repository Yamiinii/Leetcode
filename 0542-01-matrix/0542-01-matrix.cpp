class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;
        
        // Initialize distances and add all 0 cells to the queue
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for (int k = 0; k < 4; ++k) {
                int nx = i + x[k];
                int ny = j + y[k];
                
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    if (dist[nx][ny] > dist[i][j] + 1) {
                        dist[nx][ny] = dist[i][j] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return dist;
    }
};
