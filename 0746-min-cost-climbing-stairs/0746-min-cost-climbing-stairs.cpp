class Solution {
    int dp[10001];
public:
    int solve(vector<int>& cost,int size)
    {
        if(size==0)
            return cost[0];
        else if(size==1)
            return cost[1];
        if(dp[size]!=0)
            return dp[size];
        return dp[size]=cost[size]+min(solve(cost,size-1),solve(cost,size-2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        return min(solve(cost,n-1),solve(cost,n-2));
    }
};