class Solution {
    public int rec(int m,int n,int i,int j,int [][]dp)
    {
        if(i>=m || j>=n)
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(i==m-1 && j==n-1)
        return dp[i][j]=1;

        return dp[i][j]=rec(m,n,i+1,j,dp)+rec(m,n,i,j+1,dp);
    }

    public int uniquePaths(int m, int n) {
        int[][] dp=new int[m][n];
        for(int[] row:dp)
        {
            Arrays.fill(row,-1);
        }
        return rec(m,n,0,0,dp);
    }
}