class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int smallest=nums[0];
        int mid=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>mid)
                return true;
            if(nums[i]>smallest)
                mid=min(mid,nums[i]);
            
            smallest=min(nums[i],smallest);
        }
        return false;
    }
};