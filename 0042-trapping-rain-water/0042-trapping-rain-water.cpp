#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> left(n);
        vector<int> right(n);
        int sum = 0;

        // Initialize left and right arrays
        left[0] = height[0];
        right[n - 1] = height[n - 1];

        // Calculate max height from the left
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], height[i]);
        }

        // Calculate max height from the right
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], height[i]);
        }

        // Calculate water trapped at each position
        for (int i = 0; i < n; i++) {
            int waterTrapped = min(left[i], right[i]) - height[i];
            sum += waterTrapped;
        }

        return sum;
    }
};
