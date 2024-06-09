#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> remainderCount;
        remainderCount[0] = 1; // Initialize for the case where the subarray itself is divisible by k
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int remainder = sum % k;

            // Handle negative remainders to ensure they are in the range [0, k-1]
            if (remainder < 0) {
                remainder += k;
            }

            // If this remainder has been seen before, add the count of these remainders to the result
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }

            // Increment the count of this remainder in the map
            remainderCount[remainder]++;
        }

        return count;
    }
};
