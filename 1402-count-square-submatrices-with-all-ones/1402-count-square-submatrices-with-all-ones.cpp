class Solution {
public:
    int countSquares(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total=0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=grid[i][0];
            total += dp[i][0];
        }
        for(int i=1;i<m;i++)
        {
            dp[0][i]=grid[0][i];
            total += dp[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if(grid[i][j]==1)
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));

                total += dp[i][j];
            }
        }

        return total;
    }
};
