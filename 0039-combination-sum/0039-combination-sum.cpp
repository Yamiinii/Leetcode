#include <vector>
#include <algorithm>

class Solution {
public:
    void rec(const std::vector<int>& candidates, int target, std::vector<std::vector<int>>& ans, std::vector<int> v, int sum, int idx) {
        if (sum == target) {
            ans.push_back(v);
            return;
        }

        if (sum > target || idx >= candidates.size()) {
            return;
        }
        
        // Include the current element
        v.push_back(candidates[idx]);
        rec(candidates, target, ans, v, sum + candidates[idx], idx);

        // Exclude the current element and move to the next
        v.pop_back();
        rec(candidates, target, ans, v, sum, idx + 1);
    }
    
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> v;
        
        // Sort the candidates to handle duplicate combinations more effectively
        std::sort(candidates.begin(), candidates.end());
        
        rec(candidates, target, ans, v, 0, 0);
        return ans;
    }
};
