class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int trappedWater = 0;

        if (n <= 2) {
            return 0; // No trapped water possible with less than 3 bars.
        }

        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;

        while (left < right) {
            if (arr[left] <= arr[right]) {
                leftMax = max(leftMax, arr[left]);
                trappedWater += max(0, leftMax - arr[left]);
                left++;
            } else {
                rightMax = max(rightMax, arr[right]);
                trappedWater += max(0, rightMax - arr[right]);
                right--;
            }
        }

        return trappedWater;
    }
};
