class Solution {
public:
    void backtracking(vector<int>& a, int target, int i, vector<int>& current, vector<vector<int>>& result, int sum) {
        if (sum == target) {
            result.push_back(current);
            return;
        }

        if (i == a.size() || sum > target) {
            return;
        }

        // Include the current number in the combination
        current.push_back(a[i]);
        backtracking(a, target, i, current, result, sum + a[i]);
        current.pop_back();

        // Skip the current number and move to the next one
        backtracking(a, target, i + 1, current, result, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        int sum = 0;
        backtracking(candidates, target, 0, current, result, sum);
        return result;
    }
};
