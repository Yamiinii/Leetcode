class Solution {
public:
       int rec(int m, int n, int i, int j, std::vector<std::vector<int>>& dp) {
     
        if(i>=m ||j>=n)
            return 0;
           
        if (i == m - 1 && j == n - 1) {
            return dp[i][j] = 1;
        }
     
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        return dp[i][j] = rec(m,n,i+1,j,dp)+rec(m,n,i,j+1,dp);
    }
    
    int uniquePaths(int m, int n) {
       
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
 
        return rec(m, n, 0, 0, dp);
    }
};