class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>  dp(n+1,-1);
        if(n==0)
        return 0;
        if(n==1)
        return cost[0];
        // Starting from step 0 or 1 has zero cost
        dp[0] = 0;
        dp[1] = 0;
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + cost[i - 1],
                        dp[i - 2] + cost[i - 2]);
        }
        
        return dp[n];
    }
};