#include <vector>

class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<int>& marked, vector<int>& v, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        }
        
        for (int j = 0; j < nums.size(); j++) {
            if (marked[j] == 0) {
                v.push_back(nums[j]);
                marked[j] = 1;
                backtrack(nums, i + 1, marked, v, ans);
                v.pop_back();
                marked[j] = 0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> marked(nums.size(), 0);
        backtrack(nums, 0, marked, v, ans);
        return ans;
    }
};
