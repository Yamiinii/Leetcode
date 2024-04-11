class Solution {
public:
 int ways(const std::string& s, int i, std::vector<int>& dp) {
        int n = s.size();
        if (i == n) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ans = ways(s, i + 1, dp);
        if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
            ans += ways(s, i + 2, dp);
        }
        dp[i] = ans;
        return ans;
    }
    
    int numDecodings(const std::string& s) {
        if (s.empty()) {
            return 0;
        }
        std::vector<int> dp(s.size(), -1);
        return ways(s, 0, dp);
    }
};