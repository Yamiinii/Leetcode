class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mpp;

        // Count frequency of characters in string t
        for (auto ch : t) {
            mpp[ch]++;
        }

        // Count the frequency of characters in string s and adjust the frequency map
        for (auto ch : s) {
            if (mpp.find(ch) != mpp.end() && mpp[ch] > 0) {
                mpp[ch]--;
            }
        }

        int ans = 0;

        // Calculate the sum of remaining characters in t
        for (auto& pair : mpp) {
            ans += pair.second;
        }

        return ans;
    }
};
