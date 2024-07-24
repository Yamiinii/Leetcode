class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                int temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                left++;
            }
        }   
    }
};