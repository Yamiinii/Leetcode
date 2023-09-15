class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int i = m, j = n;
    string lcs;  // To store the LCS.

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs.push_back(s1[i - 1]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
                lcs.push_back(s1[i - 1]);
                i--;
            } else {
                lcs.push_back(s2[j - 1]);
                j--;
            }
        }
    }
        while(i>0)
        {
            lcs.push_back(s1[i - 1]);
            i--;
        }
        while (j>0)
        {
            lcs.push_back(s2[j - 1]);
            j--;
        }

    reverse(lcs.begin(), lcs.end());  // Reverse the LCS string.

    return lcs;
    }
};