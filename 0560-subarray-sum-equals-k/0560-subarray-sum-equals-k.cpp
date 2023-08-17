class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        int cumulativeSum = 0;
        int subarrayCount = 0;
        
        prefixSumCount[0] = 1; // Initialize to handle cases where cumulative sum equals k
        
        for (int num : nums) {
            cumulativeSum += num;
            if (prefixSumCount.find(cumulativeSum - k) != prefixSumCount.end()) {
                subarrayCount += prefixSumCount[cumulativeSum - k];
            }
            prefixSumCount[cumulativeSum]++;
        }
        
        return subarrayCount;
    }
};
