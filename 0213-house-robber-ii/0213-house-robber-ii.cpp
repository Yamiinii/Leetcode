#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + (i > 1 ? dp[i - 2] : 0), dp[i - 1]);
        }
        
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        // Scenario 1: Rob houses from the first house to the second-to-last house
        vector<int> arr1(nums.begin(), nums.end() - 1);
        
        // Scenario 2: Rob houses from the second house to the last house
        vector<int> arr2(nums.begin() + 1, nums.end());
        
        return max(solve(arr1), solve(arr2));
    }
};
