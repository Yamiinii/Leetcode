class Solution {
public:
    int solve(vector<int> &nums, int size, vector<int> &dp) {
    if (size < 0)
        return 0;
    if (size == 0)
        return nums[0];
    if (dp[size] != -1)
        return dp[size];
    
    int incl = solve(nums, size - 2, dp) + nums[size];
    int excl = solve(nums, size - 1, dp);

    return dp[size] = max(incl, excl);
}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1); // Initialize with -1 for uncomputed values
    return solve(nums, nums.size() - 1, dp);
    }
};