class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int mini=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0]=grid[0][0];
        int sum=dp[0][0];
        for(int i=1;i<m;i++)
        {
            sum+=grid[0][i];
            dp[0][i]=sum;
        }
        sum=dp[0][0];
        for(int i=1;i<n;i++)
        {
            sum+=grid[i][0];
            dp[i][0]=sum;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[n-1][m-1];
    }
};