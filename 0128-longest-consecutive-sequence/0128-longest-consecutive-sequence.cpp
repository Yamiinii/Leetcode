class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0|| n==1)
            return n;
        int maxi=1;
        int cnt=0;
        int last_smaller=INT_MIN;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1==last_smaller)
            {
                cnt++;
                last_smaller=nums[i];
            }
             else if(nums[i]!=last_smaller)//important
            {
                cnt=1;
                last_smaller=nums[i];
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};