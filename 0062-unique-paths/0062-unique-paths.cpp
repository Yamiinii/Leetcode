class Solution {
public:
       int rec(int m, int n, int i, int j, std::vector<std::vector<int>>& dp) {
     
        if (i == m - 1 && j == n - 1) {
            return dp[i][j] = 1;
        }
     
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int right = 0, down = 0;
     
        if (j + 1 < n) {
            right = rec(m, n, i, j + 1, dp);
        }
        
        if (i + 1 < m) {
            down = rec(m, n, i + 1, j, dp);
        }
        
     
        return dp[i][j] = right + down;
    }
    
    int uniquePaths(int m, int n) {
       
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
 
        return rec(m, n, 0, 0, dp);
    }
};