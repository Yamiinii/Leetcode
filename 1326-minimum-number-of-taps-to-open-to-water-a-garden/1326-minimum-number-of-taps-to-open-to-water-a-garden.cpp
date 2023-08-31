#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    int minTaps(int n, std::vector<int>& ranges) {
        std::vector<int> dp(n + 1, n + 2); // Initialize with a value greater than n
        dp[0] = 0;

        for (int i = 0; i <= n; ++i) {
            int left = std::max(0, i - ranges[i]);
            int right = std::min(n, i + ranges[i]);

            for (int j = left; j <= right; ++j) {
                dp[j] = std::min(dp[j], dp[left] + 1);
            }
        }

        return dp[n] <= n ? dp[n] : -1;
    }
};
