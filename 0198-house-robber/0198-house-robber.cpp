class Solution {
public:
    int rob(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[n - 1];
//         int n = nums.size();
//         if (n == 0) {
//             return 0;
//         }

//         vector<int> dp(n);
//         dp[0] = nums[0];

//         for (int i = 1; i < n; i++) {
//             int steps = INT_MIN;
//             for (int j = 2; j <= min(i, 2); j++) {
//                 if (i - j >= 0) {
//                     int step = dp[i - j] + nums[i];
//                     steps = max(steps, step);
//                 }
//             }
//             dp[i] = max(steps, dp[i - 1]);
//         }

//         return dp[n - 1];
        // counter example-->nums = [2, 1, 1, 2]
        // int n=nums.size();
        // int sum1;
        // for(int i=0;i<n;i=i+2)
        // {
        //     sum1+=nums[i];
        // }
        //     int sum2;
        // for(int i=1;i<n;i=i+2)
        // {
        //     sum2+=nums[i];
        // }
        // return max(sum1,sum2);
    }
};
