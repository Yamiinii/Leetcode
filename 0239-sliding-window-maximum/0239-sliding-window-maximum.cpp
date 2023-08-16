class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q; // Use a deque (double-ended queue) instead of a simple queue
        vector<int> result;

        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back(); // Remove smaller elements from the back
            }
            q.push_back(i); // Store indices instead of values in the deque
        }

        for (int i = k; i < nums.size(); i++) {
            result.push_back(nums[q.front()]); // The front of the deque contains the maximum for the current window
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front(); // Remove elements that are no longer in the current window
            }
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back(); // Remove smaller elements from the back
            }
            q.push_back(i);
        }
        
        if (!q.empty()) {
            result.push_back(nums[q.front()]); // Add the maximum for the last window
        }

        return result;
    }
};
