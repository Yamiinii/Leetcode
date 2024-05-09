#include <vector>
#include <algorithm> // for sorting

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        // Sort the happiness array in non-decreasing order
        std::sort(happiness.begin(), happiness.end());

        long long ans = 0;
        int n = happiness.size();
int j=0;
        // Iterate over the sorted array from the end to the beginning
        for (int i = n - 1; i >= 0 && k > 0; i--, k--) {
            // Adjust the happiness value of the selected child
            ans += std::max(happiness[i] - j, 0);
            j++;
        }

        return ans;
    }
};
