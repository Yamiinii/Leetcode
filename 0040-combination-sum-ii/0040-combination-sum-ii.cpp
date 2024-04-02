#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void findall(vector<int>& can, int target, vector<vector<int>>& ans, vector<int>& v, int idx) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        for (int i = idx; i < can.size(); ++i) {
            // Skip duplicates
            if (i > idx && can[i] == can[i - 1])
                continue;

            if (can[i] <= target) {
                v.push_back(can[i]);
                findall(can, target - can[i], ans, v, i + 1); // Increment idx for next recursive call
                v.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
         
        sort(candidates.begin(), candidates.end()); // Sorting candidates array
        findall(candidates, target, ans, v, 0); // Start recursive call with idx = 0
        return ans;
    }
};
