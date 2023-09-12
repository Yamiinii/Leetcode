#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool check(string s, string sub, int pos, bool isMappingExist[256][256]) {
        if (pos + sub.size() > s.size())
            return false;

        int idx = 0;
        for (int i = pos; i < pos + sub.size(); i++) {
            char sChar = s[i];
            char subChar = sub[idx];

            // Check if the characters match or a valid mapping exists
            if (sChar == subChar || isMappingExist[subChar][sChar]) {
                idx++;
            } else {
                return false;
            }
        }
        return true;
    }

    bool matchReplacement(string s, string sub,vector<vector<char>>& mappings) {
        bool isMappingExist[256][256] = {false}; // Initialize with ASCII character range
        for (int i = 0; i < mappings.size(); i++) {
            char subChar = mappings[i][0];
            char sChar = mappings[i][1];
            isMappingExist[subChar][sChar] = true;
        }
        for (int i = 0; i < s.size(); i++) {
            if (check(s, sub, i, isMappingExist)) {
                return true;
            }
        }
        return false;
    }
};

