const int N = 2005; // Use a more dynamic approach in practice
class Solution {
public:
    vector<vector<int>> isPalin; // Dynamic size

    bool isPalindrome(string &s, int i, int j) {
        if (i > j) return true; // Edge case for empty substring
        if (i == j) return true; // Single character is always a palindrome
        if (isPalin[i][j] != -1) return isPalin[i][j];
        
        // Check palindrome status
        while (i < j) {
            if (s[i] != s[j]) {
                return isPalin[i][j] = false;
            }
            i++;
            j--;
        }
        return isPalin[i][j] = true;
    }
    
    int helper(string &s, int start, vector<int>& dp) {
        if (start >= s.size()) 
            return 0;
        
        if (dp[start] != -1)
            return dp[start];
        
        int ans = INT_MAX;
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                ans = min(ans, 1 + helper(s, end + 1, dp));
            }
        }
        
        return dp[start] = ans;
    }
    
    int minCut(string s) {
        int n = s.size();
        isPalin.resize(n, vector<int>(n, -1)); // Initialize the isPalin table dynamically
        vector<int> dp(n, -1);
        return helper(s, 0, dp) - 1;  // Subtract 1 to get the number of cuts
    }
};
