#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(int k, int n, vector<vector<int>>& ans, vector<int>& v, int start) {
        if(n==0 && v.size()==k)
            ans.push_back(v);
        
        if (v.size() > k || n < 0) {
            return;
        }
        
        for(int i=start;i<=9;i++)
        {
            v.push_back(i);
             backtrack(k, n-i, ans, v, i+1);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        backtrack(k, n, ans, v, 1); // Start from number 1
        return ans;
    }
};
