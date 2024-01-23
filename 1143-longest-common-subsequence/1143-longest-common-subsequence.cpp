#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(const std::string& text1, const std::string& text2, int i, int j, std::vector<std::vector<int>>& dp) {
        // Base cases
        if (i == 0 || j == 0) {
            return 0;
        }

        // Check if the result is already memoized
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (text1[i - 1] == text2[j - 1]) {
            return dp[i][j] = 1 + solve(text1, text2, i - 1, j - 1, dp);
        } else {
            return dp[i][j] = std::max(solve(text1, text2, i, j - 1, dp), solve(text1, text2, i - 1, j, dp));
        }
    }

    int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
        int m = text1.size();
        int n = text2.size();

        // Initialize memoization table with -1
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, -1));

        // Call the recursive function with memoization
        return solve(text1, text2, m, n, dp);
    }
};
