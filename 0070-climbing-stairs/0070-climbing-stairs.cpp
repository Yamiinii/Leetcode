class Solution {
public:
    int rec(int n,vector<int>& dp)
    {
        if(dp[n]!=0)
            return dp[n];
        if(n==1)
            return dp[n]=1;
        if(n==2)
            return dp[n]=2;
        if(n<=0)
            return dp[n];
        return dp[n]=rec(n-1,dp)+rec(n-2,dp
);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        rec(n,dp);
        return dp[n];
    }
};