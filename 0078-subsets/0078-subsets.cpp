class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int pow_set_size = pow(2, nums.size());
        
         for (int counter = 0; counter < pow_set_size; counter++) {
             vector<int> v;
        for (int j = 0; j < nums.size(); j++) {
            // Check if jth bit in the counter is set
            // If set then print jth element from set
            if (counter & (1 << j))
                v.push_back(nums[j]);
        }
        ans.push_back(v);
    }
        return ans;
    }
};