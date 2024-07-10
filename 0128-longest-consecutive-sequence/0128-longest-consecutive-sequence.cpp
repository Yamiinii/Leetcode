class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int cnt=0;
        int maxi=1;
        int lastSmaller=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1==lastSmaller)
            {
                cnt+=1;
                lastSmaller=nums[i];
            }
            else if(nums[i]!=lastSmaller)//important
            {
                cnt=1;
                lastSmaller=nums[i];
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};