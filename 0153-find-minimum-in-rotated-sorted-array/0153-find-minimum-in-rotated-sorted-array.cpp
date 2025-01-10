class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        if(nums[0]<nums[n-1])
        return nums[0];

        int left=0;
        int right=n-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[right])
            {
                if(nums[mid+1]<nums[mid])
                return nums[mid+1];
                else
                left=mid+1;
            }
            else
            {
                if(nums[mid-1]>nums[mid])
                return nums[mid];
                else
                right=mid;
            }
        }

        return 0;
    }
};