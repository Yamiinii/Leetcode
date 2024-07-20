class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<mini)
                mini=nums[i];
            if(nums[i]>maxi)
                maxi=nums[i];
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mini && nums[i]<maxi)
                cnt++;
        }
        return cnt;
        
    }
};