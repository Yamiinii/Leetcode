class Solution {
    public int maximalSquare(char[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        int[][] dp=new int[n][m];
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            dp[i][0]=matrix[i][0]-'0';
            maxi=Math.max(maxi,dp[i][0]);
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i]-'0';
            maxi=Math.max(maxi,dp[0][i]);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                   dp[i][j] = 1 + Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                    maxi=Math.max(maxi,dp[i][j]);
                }
                else
                dp[i][j]=0;
            }
        }
        return maxi*maxi;
    }
}