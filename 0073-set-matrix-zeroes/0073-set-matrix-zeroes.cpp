class Solution {
public:
    //////////////////////better
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Boolean arrays to track which rows and columns need to be zeroed
        vector<bool> zeroRow(n, false);
        vector<bool> zeroCol(m, false);
        
        // First pass: Mark rows and columns to be zeroed
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    zeroRow[i] = true;
                    zeroCol[j] = true;
                }
            }
        }
        
        // Second pass: Zero out marked rows and columns
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (zeroRow[i] || zeroCol[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
