#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    void generateAllStrings(const std::vector<std::string>& nums, int n, int i, std::string& s, std::vector<std::string>& big) {
        if (i == n) {
            big.push_back(s);
            return;
        }

        s[i] = '0';
        generateAllStrings(nums, n, i + 1, s, big);
        s[i] = '1';
        generateAllStrings(nums, n, i + 1, s, big);
    }

    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        int n = nums[0].size();
        std::string s(n, '0');
        std::vector<std::string> big;

        generateAllStrings(nums, n, 0, s, big);
        
        // Sort both arrays
        sort(nums.begin(), nums.end());
        sort(big.begin(), big.end());

        for (int i = 0; i < big.size(); i++) {
            if (std::find(nums.begin(), nums.end(), big[i]) == nums.end())
                return big[i];
        }

        return "";
    }
};
