class Solution {
public:
    //we can count the values and then put
    //for mid dont do anything
    void sortColors(vector<int>& nums) {
        int start=0;
        int mid=0;
        int end=nums.size()-1;
        while (mid <= end)
        {
            if(nums[mid]==0)
            {
                swap(nums[start],nums[mid]);
                mid++;
                start++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
       else { // nums[mid] == 2
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }
};