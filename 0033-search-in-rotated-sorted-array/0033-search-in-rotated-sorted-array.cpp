class Solution {
public:
    int binarySearch(vector<int>& nums, int target)
    {
        int left=0;
        int right=nums.size()-1;

        while(left<=right)
        {
//             | Formula                       | Safe? | Reason                         |
// | ----------------------------- | ----- | ------------------------------ |
// | `mid = (left + right)/2`      | ❌     | May cause integer overflow     |
// | `mid = left + (right-left)/2` | ✅     | No overflow, standard practice |

            int mid=left+(right-left)/2;

            if(nums[mid]==target)
            return mid;

            //check if the left half is sorted or right half
            if(nums[left]<=nums[mid])
            {
                if(nums[left]<=target && nums[mid]>target)
                right=mid-1;
                else
                left=mid+1;
            }
            else
            {
                if(nums[mid]<target && nums[right]>=target)
                left=mid+1;
                else
                right=mid-1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pos=binarySearch(nums,target);
        return pos;
    }
};