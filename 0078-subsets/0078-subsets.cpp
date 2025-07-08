class Solution {
public:
    void backtrack(int idx,vector<int>& nums,vector<vector<int>>& ans,vector<int>& v)
    {
        ans.push_back(v);
        for(int i=idx;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            backtrack(i+1,nums,ans,v);
            v.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n==0)
        return ans;
        vector<int> v;
        backtrack(0,nums,ans,v);
        return ans;
    }
};