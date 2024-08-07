class Solution {
public:
    int subarray(vector<int>& nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> map; 
        int count = 0, start = 0, end = 0;  
        while (end < n) {  
            map[nums[end]]++;  
            while (map.size() > k) {  
                map[nums[start]]--; 
                if (map[nums[start]] == 0) {  
                    map.erase(nums[start]);
                }
                start++; 
            }
            count += end - start + 1; 
            end++;  
        }
        return count; 
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums,k)-subarray(nums,k-1);
    }
};