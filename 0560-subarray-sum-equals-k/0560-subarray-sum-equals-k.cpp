class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int ans = 0;
        unordered_map<int, int> prefixSumCount; // Stores the count of prefix sums
        prefixSumCount[0] = 1; // Initialize with prefix sum 0
        
        for (int i = 0; i < nums.size(); i++) {
            ans += nums[i];
            
            // Check if there is a prefix sum such that ans - prefix_sum = k
            if (prefixSumCount.find(ans - k) != prefixSumCount.end()) {
                cnt += prefixSumCount[ans - k];
            }
            
            // Increment the count of the current prefix sum
            prefixSumCount[ans]++;
        }
        
        return cnt;
    }
};
