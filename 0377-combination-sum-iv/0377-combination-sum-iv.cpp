class Solution {
public:
    int combn(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1;   // Base case: There is 1 way to make target 0, which is to use no elements.
        if (target < 0) return 0;    // Base case: No way to make a negative target.

        if (dp[target] != -1) return dp[target];  // Return already computed value.

        int ans = 0;
        for (int num : nums) {
            ans += combn(nums, target - num, dp);  // Recursive call with reduced target.
        }

        return dp[target] = ans;  // Memoize and return the computed value.
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);  // Initialize memoization vector with -1.
        return combn(nums, target, dp);
    }
};
