class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(i==0)
                {
                    dp[i][j]=matrix[i][j];
                    mini=min(mini,dp[i][j]);
                    continue;
                }
                
                int up=matrix[i][j];
                int left=matrix[i][j];
                int right=matrix[i][j];
                
                if(j>0)
                    left+=dp[i-1][j-1];
                else
                    left=INT_MAX;
                if(j<n-1)
                    right+=dp[i-1][j+1];
                else
                    right=INT_MAX;
                up+=dp[i-1][j];
                
                dp[i][j]=min(left,min(right,up));
                mini=min(mini,dp[i][j]);
            }
            ans=mini;
        }
        return ans;
    }
};