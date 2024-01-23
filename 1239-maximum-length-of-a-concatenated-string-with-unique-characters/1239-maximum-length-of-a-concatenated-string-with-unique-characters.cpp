#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(const std::string& currentString, const std::string& newString) {
        std::unordered_map<char, int> charFreq;

        // Update frequency for characters in currentString
        for (char c : currentString) {
            charFreq[c]++;
            if (charFreq[c] > 1) {
                return false;  // Not unique
            }
        }

        // Update frequency for characters in newString
        for (char c : newString) {
            charFreq[c]++;
            if (charFreq[c] > 1) {
                return false;  // Not unique
            }
        }

        return true;  // Unique
    }

    void solve(std::vector<std::string>& arr, std::string current, int start, int& max_len) {
        if (current.size() > max_len) {
            max_len = current.size();
        }

        for (int i = start; i < arr.size(); i++) {
            if (!isValid(current, arr[i])) {
                continue;
            }

            solve(arr, current + arr[i], i + 1, max_len);
        }
    }

    int maxLength(std::vector<std::string>& arr) {
        int max_len = 0;
        solve(arr, "", 0, max_len);
        return max_len;
    }
};
