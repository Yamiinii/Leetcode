class Solution {
public:
    int characterReplacement(string s, int k) {
        int head = 0, ans = 0;
        int n = s.size();
        vector<int> charCount(26, 0); // Store counts of each character
        int maxCount = 0; // Maximum character count in the current window

        for (int tail = 0; head < n; head++) {
            charCount[s[head] - 'A']++;
            maxCount = max(maxCount, charCount[s[head] - 'A']);

            // Calculate the number of characters to replace
            int replaceCount = (head - tail + 1) - maxCount;

            // If the number of characters to replace is greater than k, move the tail
            if (replaceCount > k) {
                charCount[s[tail] - 'A']--;
                tail++;
            }

            // Update the maximum length
            ans = max(ans, head - tail + 1);
        }

        return ans;
    }
};
