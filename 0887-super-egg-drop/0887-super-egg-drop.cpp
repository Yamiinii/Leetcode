class Solution {
public:
    int solve(int k, int f,vector<vector<int>> &dp)
    {
        if(f==0||f==1||k==1)
            return dp[k][f]=f;
        if(dp[k][f]!=-1)
            return dp[k][f];
        int low=1;
        int high=f;
        int mn = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            
            int left = solve(k-1, mid-1,dp);
            int right = solve(k, f-mid,dp);
            
            int temp=1+max(left,right);
            
            if(left < right) 
                low = mid+1;
            else 
                high = mid-1;   
            mn = min(mn, temp);
        }
        
        return dp[k][f]=mn;
        
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};