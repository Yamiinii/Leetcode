class Solution {
public:
       int search_int(vector<int>& nums, int target) {
        int lo=0;
        int high=nums.size()-1;
        while (lo <= high) {
            int mid = lo + (high - lo) / 2;
            if (nums[mid] == target)
                return true;
            
            if (nums[lo] == nums[mid] && nums[mid] == nums[high]) {
                lo++;
                high--;
            } else if (nums[lo] <= nums[mid]) {
                if (nums[lo] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    lo = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[high])
                    lo = mid + 1;
                else
                    high = mid - 1;
            }
        }
         return -1;
    }
    bool search(vector<int>& nums, int target) {
       if(search_int(nums,target)!=-1)
       return true;
       return false;

    }
};