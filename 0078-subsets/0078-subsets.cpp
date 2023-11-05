class Solution {
public:
    void recursion(vector<int>& nums, vector<vector<int>>& ans, int i, int n, vector<int>& v) {
        if (i == n) {
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[i]);
        recursion(nums, ans, i + 1, n, v);
        v.pop_back();
        recursion(nums, ans, i + 1, n, v);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        recursion(nums, ans, 0, n, v);
        return ans;
    }
};
