class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int head = 0, tail = 0, ans = 0;
        int n = nums.size();
        unordered_map<int, int> mpp;
        int currentSum = 0; // Keep track of the current subarray sum

        while (head < n) {
            mpp[nums[head]]++;
            currentSum += nums[head];

            while (mpp[nums[head]] > 1) {
                mpp[nums[tail]]--;
                currentSum -= nums[tail];
                tail++;
            }

            ans = max(ans, currentSum);
            head++;
        }

        return ans;
    }
};
