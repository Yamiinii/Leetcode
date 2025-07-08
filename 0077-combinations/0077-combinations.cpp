class Solution {
public:
    void backtrack(int num,int n ,vector<vector<int>>&ans,vector<int>& v,int k)
    {
        if(v.size()==k)
        {ans.push_back(v);
         return;
        }

        if (num > n) return;
        
        v.push_back(num);
         backtrack(num+1,n,ans,v,k);
            v.pop_back();
            backtrack(num+1,n,ans,v,k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        backtrack(1,n,ans,v,k);
        return ans;
    }
};