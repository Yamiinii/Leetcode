class Solution {
public:
    int rec(int m,int n,vector<vector<int>> &dp,int i,int j)
    {
        if(i==m-1 || j==n-1)
        return 1;

        if (i >= m || j >= n)
            return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int right=rec(m,n,dp,i+1,j);
        int down=rec(m,n,dp,i,j+1);

        return dp[i][j]=right+down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return rec(m,n,dp,0,0);
    }
};