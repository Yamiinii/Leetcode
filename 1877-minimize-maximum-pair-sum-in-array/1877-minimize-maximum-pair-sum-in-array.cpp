class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=INT_MIN;
        for(int i=0;i<nums.size()/2;i++)
        {
            int sum=nums[i]+nums[nums.size()-i-1];
            maxi=max(maxi,sum);
        }
        
        return maxi;
    }
};