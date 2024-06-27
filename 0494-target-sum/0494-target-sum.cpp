class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        
        int sum2 = (target + sum) / 2;
        
        if (sum < target || (sum + target) < 0 || (sum + target) % 2 != 0) {
            return 0; // If conditions for no solution are met
        }
        
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum2 + 1, 0));
        dp[0][0] = 1; // Base case: one way to achieve sum 0 (by choosing the empty subset)

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= sum2; ++j) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum2];
    }
};
