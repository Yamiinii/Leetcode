class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       // Check if the input vector is empty.
       if (nums.empty()) {
           return 0;
       }

       vector<unsigned int> dp(target + 1, 0); // Initialize a vector with unsigned int.

       // There is one way to make a sum of 0 (by not selecting any number).
       dp[0] = 1;

       for (int i = 1; i <= target; ++i) {
           for (int num : nums) {
               if (i >= num) {
                   dp[i] += dp[i - num];
               }
           }
       }

       return dp[target];
   }
};
