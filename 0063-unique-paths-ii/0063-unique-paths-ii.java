class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // If starting cell has an obstacle, return 0 as no paths possible
        if (grid[0][0] == 1) 
            return 0;

        int[][] dp = new int[m][n];

        // Initialize first column
        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) 
                break;
            dp[i][0] = 1;
        }

        // Initialize first row
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1) 
                break;
            dp[0][j] = 1;
        }

        // Fill the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m-1][n-1];
    }
}
