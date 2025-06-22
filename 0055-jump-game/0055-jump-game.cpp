class Solution {
public:
    int rec(vector<int>& nums,int i,vector<int>& dp)
    {
        if(i>=nums.size()-1)
      {  dp[i]=1;
        return dp[i];}

        if(dp[i]!=-1)
        return dp[i];

        int maxi_jump=nums[i];
        for(int j=1;j<=maxi_jump;j++)
        {
            if(rec(nums,i+j,dp))
            return dp[i]=1;
        }
    
        return dp[i]=0;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        rec(nums,0,dp);
        return dp[nums.size()-1]==1?true:false;
    }
};