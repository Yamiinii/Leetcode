class Solution {
public:
    void backtrack(int num,int n ,vector<vector<int>>&ans,vector<int>& v,int k)
    {
        if(v.size()==k)
        ans.push_back(v);
        for(int i=num;i<=n;i++)
        {
            v.push_back(i);
            backtrack(i+1,n,ans,v,k);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        backtrack(1,n,ans,v,k);
        return ans;
    }
};