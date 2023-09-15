class Solution {
public:
    int longestPalindromeSubseq(string text1) {
        int n = text1.size();
        string text2 = text1; // Copy the input string.

        // Reverse the copy of the input string.
        reverse(text2.begin(), text2.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][n]; // The length of the longest palindromic subsequence.
    }
};
