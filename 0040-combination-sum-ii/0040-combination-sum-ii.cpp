#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rec(const std::vector<int>& candidates, int target, std::vector<std::vector<int>>& ans, std::vector<int> v, int idx) {
        if (target==0) {
            ans.push_back(v);
            return;
        }
        
        if(target<0)
            return;
        
        for (int i = idx; i < candidates.size(); ++i) {
            // // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] <= target) {
                v.push_back(candidates[i]);
                rec(candidates, target-candidates[i], ans,v, i+1); // Increment idx for next recursive call
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     std::vector<std::vector<int>> ans;
        std::vector<int> v;
        
        // Sort the candidates to handle duplicate combinations more effectively
        std::sort(candidates.begin(), candidates.end());
        
        rec(candidates, target, ans, v, 0);
        return ans;
    }
};
