#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(int k, int n, vector<vector<int>>& ans, vector<int>& v, int start) {
        // Base case: if combination size is k and sum is n, add to results
        if (v.size() == k && n == 0) {
            ans.push_back(v);
            return;
        }
        
        // If the combination size exceeds k or sum becomes negative, stop
        if (v.size() > k || n < 0) {
            return;
        }
        
        // Try to add numbers from 'start' to 9
        for (int i = start; i <= 9; ++i) {
            v.push_back(i);
            backtrack(k, n - i, ans, v, i + 1); // Move to the next number
            v.pop_back(); // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        backtrack(k, n, ans, v, 1); // Start from number 1
        return ans;
    }
};
