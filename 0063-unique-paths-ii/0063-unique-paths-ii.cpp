class Solution {
public:
    int rec(int m,int n,vector<vector<int>> &dp,int i,int j,vector<vector<int>>& grid)
    {
        // if(i==m-1 || j==n-1)
        // return 1;
        if(i==m-1 && j==n-1)
        return grid[i][j]==0?1:0;

        if (i >= m || j >= n || grid[i][j]==1)
            return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        int right=rec(m,n,dp,i+1,j,grid);
        int down=rec(m,n,dp,i,j+1,grid);

        return dp[i][j]=right+down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return rec(m,n,dp,0,0,obstacleGrid);
    }
};