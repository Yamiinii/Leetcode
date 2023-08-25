class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> ans(r, vector<int>(c, 0));
        vector<vector<int>> visited(r, vector<int>(c, 0));
        queue<pair<pair<int, int>, int>> q;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            ans[i][j] = dist;

            for (int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < r && nj >= 0 && nj < c && visited[ni][nj] == 0) {
                    visited[ni][nj] = 1;
                    q.push({{ni, nj}, dist + 1});
                }
            }
        }

        return ans;
    }
};
