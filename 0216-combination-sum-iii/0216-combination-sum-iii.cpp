class Solution {
public:
       void findall(int k, int n, vector<vector<int>>& ans, vector<int> v, int i) {
        if (i == 10 || k == 0 || n == 0) { // Condition i == 10 because numbers are from 1 to 9
            if (k == 0 && n == 0) // Check if both k and n are zero
                ans.push_back(v);
            return;
        }
        
        if (i <= n) { // We can't select a number greater than n
            v.push_back(i);
            findall(k - 1, n - i, ans, v, i + 1); // Decrease k and n, and go to next number
            v.pop_back();
        }
        
        findall(k, n, ans, v, i + 1); // Skip current number
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        findall(k,n,ans,v,1);
        return ans;
    }
};