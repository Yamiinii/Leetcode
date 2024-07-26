class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int left=0;
        int right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]<=nums[right])
                return nums[left];
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
                if(nums[mid-1] > nums[mid])
                    return nums[mid];
                else
                    right = mid-1;
            }
        }
        
        return -1;
    }
};