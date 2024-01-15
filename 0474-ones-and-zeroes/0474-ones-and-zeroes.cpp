#include <vector>
#include <string>

class Solution {
public:
    int rec(int i, vector<vector<vector<int>>>& dp, vector<string>& strs, int m, int n) {
        int size = strs.size();
        if (i >= size)
            return 0;
        if (dp[i][m][n] != -1)
            return dp[i][m][n];
        int zc = count(strs[i].begin(), strs[i].end(), '0');
       int oc = count(strs[i].begin(), strs[i].end(), '1');

        if (m - zc >= 0 && n - oc >= 0)
            return dp[i][m][n] = max(1 + rec(i + 1, dp, strs, m - zc, n - oc), rec(i + 1, dp, strs, m, n));
        else
            return dp[i][m][n] = rec(i + 1, dp, strs, m, n);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return rec(0, dp, strs, m, n);
    }
};
