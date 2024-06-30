#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0]; // Initialize max_sum to the first element
        int curr_sum = nums[0]; // Initialize curr_sum to the first element
        int left=0;
        for (int right = 1; right < n; right++) {
            // Slide the window to the right, expand by adding nums[right]
            curr_sum += nums[right];
            
            // Check if we should contract the window from the left
            while (curr_sum < nums[right]) {
                curr_sum =curr_sum- nums[left];
                left++;
            }
            
            // Update max_sum if curr_sum is greater
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
            }
        }
        
        return max_sum;
    }
};


