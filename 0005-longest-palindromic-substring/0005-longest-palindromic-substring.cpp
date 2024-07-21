#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        // Initialize a 2D dp table where dp[i][j] will be true if s[i...j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;   // Starting index of the longest palindrome substring
        int maxLen = 1;  // Length of the longest palindrome substring (minimum is 1 for single character)

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check for substrings of length > 2
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;  // Ending index of substring

                // Check if s[i...j] is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        // Extract the longest palindrome substring from s using start and maxLen
        return s.substr(start, maxLen);
    }
};
