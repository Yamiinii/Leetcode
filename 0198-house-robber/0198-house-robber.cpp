class Solution {
public:
    int rec(vector<int> & nums,vector<int> & dp,int i)
    {
        if(i>=nums.size())
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        int ans=0;
        int take=nums[i]+rec(nums,dp,i+2);
        int not_take=rec(nums,dp,i+1);

        ans=max(take,not_take);

        return dp[i]=ans;
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return rec(nums,dp,0);
    }
};