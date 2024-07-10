class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int maxi = 0;
        int start = 0;
        int n = s.size();

        for (int end = 0; end < n; end++) {
            char currentChar = s[end];

            if (mpp.find(currentChar) != mpp.end() && mpp[currentChar] >= start) {
                // If current character is already in the map and its index is within the current window
                start = mpp[currentChar] + 1;
            }

            // Update the position of the current character in the map
            mpp[currentChar] = end;

            // Update the maximum length of substring without repeating characters
            maxi = max(maxi, end - start + 1);
        }

        return maxi;
    }
};
