class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>> &visited)
    {
        if(i>=n ||i<0 ||j>=m||j<0 ||visited[i][j]!=-1||grid[i][j]==0)
        {
            return 0;
        }
        visited[i][j] = 1;
        int up = solve(grid, i - 1, j,n,m, visited);
        int down = solve(grid, i + 1, j, n,m,visited);
        int left = solve(grid, i, j - 1,n,m, visited);
        int right = solve(grid, i, j + 1,n,m, visited);

        visited[i][j] =-1;

        return grid[i][j] + max({up, down, left, right});
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        vector<vector<int>> visited(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    maxi=max(maxi,solve(grid,i,j,n,m,visited));
                }
            }
        }
        return maxi;
    }
};