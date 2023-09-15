class Solution {
public:
    int minInsertions(string text1) {
        int m = text1.size();
        string text2 = text1;
        reverse(text2.begin(), text2.end());
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

    // int deletion=text1.size()-dp[m][m];
        int insertion=text2.size()-dp[m][m];
        return insertion;
    }
};