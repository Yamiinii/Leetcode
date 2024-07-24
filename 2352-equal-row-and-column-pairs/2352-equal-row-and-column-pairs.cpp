class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> rows;
        unordered_map<string, int> cols;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        // Calculate row hashes
        for (int i = 0; i < n; i++) {
            string rowhash;
            for (int j = 0; j < m; j++) {
                rowhash += to_string(grid[i][j]) + " ";
            }
            rows[rowhash]++;
        }

        // Calculate column hashes
        for (int j = 0; j < m; j++) {
            string colhash;
            for (int i = 0; i < n; i++) {
                colhash += to_string(grid[i][j]) + " ";
            }
            cols[colhash]++;
        }

        // Count equal pairs
        for (auto& row : rows) {
            for (auto& col : cols) {
                if (row.first == col.first) {
                    ans += row.second * col.second;
                }
            }
        }

        return ans;
    }
};
