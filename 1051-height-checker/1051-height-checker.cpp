#include <vector>
#include <algorithm>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        std::vector<int> asc = heights; // Copy the heights vector
        std::sort(asc.begin(), asc.end()); // Sort the copied vector
        int cnt = 0; // Initialize the counter to 0

        // Compare the original and sorted vectors
        for (int i = 0; i < asc.size(); i++) {
            if (heights[i] != asc[i]) {
                cnt++;
            }
        }

        return cnt;
    }
};
