class Solution {
public:
    int rec(vector<int> & cost,int idx,vector<int> & dp)
    {
        int n=cost.size();
        if(idx>=n)
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        return dp[idx]=cost[idx]+min(rec(cost,idx+1,dp),rec(cost,idx+2,dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>  dp(n+1,-1);
        dp[n]=min(rec(cost,0,dp),rec(cost,1,dp));
        return dp[n];
    }
};