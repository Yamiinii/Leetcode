class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false; // If the sum is odd, can't partition into equal subsets
        }

        int target = sum / 2;

        // Create a DP array to keep track of whether a sum can be achieved using a subset of nums
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: empty subset can achieve a sum of 0

        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        return dp[target];
    }
};
