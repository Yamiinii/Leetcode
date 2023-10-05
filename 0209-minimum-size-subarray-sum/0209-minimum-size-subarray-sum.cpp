class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int front = 0, back = 0;
        int minLength = INT_MAX; // Initialize with a large value
        int currentSum = 0;
        int n = nums.size();

        while (front < n) {
            currentSum += nums[front];

            while (currentSum >= target) {
                // Update the minimum length
                minLength = min(minLength, front - back + 1);

                // Move the back pointer to the right and subtract nums[back] from the sum
                currentSum -= nums[back];
                back++;
            }

            front++;
        }
         if(minLength==INT_MAX){
            return 0;
        }
        return minLength;
    }
};