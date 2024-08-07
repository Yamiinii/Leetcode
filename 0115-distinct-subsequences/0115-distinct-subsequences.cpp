class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        // Use long long for larger values
      vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        
        // An empty string t is a subsequence of any prefix of s
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    // Case 1: When characters match
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                } else {
                    // Case 2: When characters don't match
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

       return (int)dp[n][m];
    }
};