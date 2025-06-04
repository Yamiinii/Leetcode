class Solution {
public:
    int rec(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j,int n,int m,int curr_sum)
    {
         if (i >= n || j >= m) return 1e9; // Out of bounds
        if (i == n - 1 && j == m - 1) return grid[i][j]; // Destination

        if(dp[i][j]!=-1)
        return dp[i][j];
        int right = rec(grid, dp, i, j + 1, n, m,curr_sum);
        int down = rec(grid, dp, i + 1, j, n, m,curr_sum);
        return dp[i][j] = grid[i][j] + min(right, down);

    }

    int minPathSum(vector<vector<int>>& grid) {
        int mini=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return rec(grid,dp,0,0,n,m,0);
    }
};