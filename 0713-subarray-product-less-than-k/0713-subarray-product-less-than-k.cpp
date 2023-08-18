class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0; // No subarray will have a product less than or equal to 0
        }

        int n = nums.size();
        int left = 0;
        int product = 1;
        int count = 0;

        for (int right = 0; right < n; ++right) {
            product *= nums[right];
            
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            
            // The number of subarrays that end at the current right index
            // and have a product less than k is equal to the size of the window
            // (right - left + 1).
            count += right - left + 1;
        }

        return count;
    }
};
