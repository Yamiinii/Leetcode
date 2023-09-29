class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;  // Assume it's increasing
        bool decreasing = true;  // Assume it's decreasing
        
        // Loop through the vector to check monotonicity
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false;  // If we find an increasing pair, mark decreasing as false
            } else if (nums[i] < nums[i - 1]) {
                increasing = false;  // If we find a decreasing pair, mark increasing as false
            }
            
            // If both flags are false, it's neither increasing nor decreasing, so return false
            if (!increasing && !decreasing) {
                return false;
            }
        }
        
        // If we reach here, it's either increasing or decreasing or both
        return true;
    }
};
