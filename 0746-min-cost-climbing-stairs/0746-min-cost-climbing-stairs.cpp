class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        
        // Initialize the DP array with the cost of the first two steps.
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for (int i = 2; i < n; i++) {
            // Calculate the minimum cost to reach the current step.
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        
        // The final answer is the minimum cost to reach the last step or the second-to-last step.
        return min(dp[n - 1], dp[n - 2]);
    }
};
