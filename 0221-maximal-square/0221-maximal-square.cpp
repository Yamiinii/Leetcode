class Solution {
public:
     int rec(vector<vector<char>>& matrix,int i,int j,int n,int m,vector<vector<int>> &dp,int &maxi)
    {
        if(i>=n || j>=m || matrix[i][j]=='0')
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int right=rec(matrix,i,j+1,n,m,dp,maxi);
        int down=rec(matrix,i+1,j,n,m,dp,maxi);
        int diagonal=rec(matrix,i+1,j+1,n,m,dp,maxi);
        if(matrix[i][j]=='1')
        {
            dp[i][j]=1+min({right,down,diagonal});
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else
        return dp[i][j]=0;

    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi=0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rec(matrix, i, j, n, m, dp, maxi);
            }
        }
        return maxi*maxi;
    }
};