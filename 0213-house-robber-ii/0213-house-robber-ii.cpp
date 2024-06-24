class Solution {
public:
    int solve(vector<int>& nums)
    {
        vector<int> dp(nums.size(),0);
        int n=nums.size();
                if (n == 0) return 0;
        if (n == 1) return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int take=nums[i]+dp[i-2];
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
int n=nums.size();
        if(n==1)
            return nums[0];
 vector<int> arr1(nums.begin() + 1, nums.end());
        
        // Option 2: Exclude the last house
        vector<int> arr2(nums.begin(), nums.end() - 1);
        return max(solve(arr1),solve(arr2));
    }
};