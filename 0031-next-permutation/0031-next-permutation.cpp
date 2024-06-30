class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int dip = -1;
        
        // Step 1: Find the largest index dip such that nums[dip] < nums[dip+1]
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                dip = i;
                break;
            }
        }
        
        // Step 2: If dip is -1, nums is the last permutation, so reverse it to get the first permutation
        if (dip == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 3: Find the smallest number greater than nums[dip] from dip+1 to n-1
        int mini = nums[dip + 1];
        int number = dip + 1;
        
        for (int idx = dip + 1; idx < n; idx++) {
            if (nums[idx] > nums[dip] && nums[idx] < mini) {
                mini = nums[idx];
                number = idx;
            }
        }
        
        // Step 4: Swap nums[dip] and nums[number]
        swap(nums[dip], nums[number]);
        
        // Step 5: Sort nums from dip+1 to the end to get the next permutation
        sort(nums.begin() + dip + 1, nums.end());
    }
};
