class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; // If there are no houses, return 0
        if (n == 1) return nums[0]; // If there is only one house, rob it
        
        vector<int> dp(n, 0);
        
        // Base cases
        dp[0] = nums[0]; // Rob the first house
        dp[1] = max(nums[0], nums[1]); // Rob either the first or the second house
        
        // Iterate over each house starting from the third one
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        // Return the maximum amount that can be robbed without triggering an alarm
        return dp[n - 1];
    }
};
