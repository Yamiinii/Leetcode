class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int head = 0;
        int tail = 0;
        int ans = 1;
        int final_ans = 0;
        int n = nums.size();

        for (head = 0; head < n; head++) {
            ans *= nums[head];

            // Shrink the window from the left if ans >= k
            while (ans >= k && tail <= head) {
                ans /= nums[tail];
                tail++;
            }

            // Count subarrays within the valid product range
            final_ans += (head - tail + 1);
        }

        return final_ans;
    }
};
