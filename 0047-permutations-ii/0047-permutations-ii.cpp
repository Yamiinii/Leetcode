#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& v, unordered_map<int, int>& mpp) {
        if (v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        
        for (auto& [num, freq] : mpp) {
            if (freq > 0) {
                v.push_back(num);
                freq--;
                backtrack(nums, ans, v, mpp);
                freq++; // Revert the changes after backtracking
                v.pop_back(); // Remove the last element from the current permutation
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        unordered_map<int, int> mpp;
        
        for (auto num : nums) {
            mpp[num]++;
        }
        
        backtrack(nums, ans, v, mpp);
        return ans;
    }
};
