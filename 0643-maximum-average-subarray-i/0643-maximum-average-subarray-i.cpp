class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        int n = nums.size();
        
        // Calculate sum of first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        // Initialize avg with the average of first k elements
        double avg = sum / k;
        
        // Slide window and calculate maximum average
        for (int i = 1; i <= n - k; i++) {
            sum = sum - nums[i - 1] + nums[i + k - 1]; // Slide window
            avg = max(avg, sum / k); // Update avg if current average is greater
        }
        
        return avg;
    }
};
