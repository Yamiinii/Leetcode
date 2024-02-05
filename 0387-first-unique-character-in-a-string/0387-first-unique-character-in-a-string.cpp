#include <unordered_map>
#include <string>

class Solution {
public:
    int firstUniqChar(std::string s) {
        std::unordered_map<char, int> mpp;

        // Count occurrences of each character in the string
        for (char c : s) {
            mpp[c]++;
        }

        // Find the first unique character and return its index
        for (int i = 0; i < s.size(); ++i) {
            if (mpp[s[i]] == 1) {
                return i;
            }
        }

        // If no unique character found, return -1
        return -1;
    }
};
