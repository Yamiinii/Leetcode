class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int n=nums.size();
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
        int maxi_jump = nums[i];
            for (int j = 1; j <= maxi_jump && i + j < n; j++) {
                if (dp[i + j] == 1) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[0]==1;
    }
};