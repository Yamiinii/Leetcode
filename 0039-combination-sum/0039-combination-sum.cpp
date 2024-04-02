class Solution {
public:
    void findall(int idx,vector<int>& candidates, int target,vector<int> &v,vector<vector<int>> &ans)
    {

        if(idx==candidates.size())
        {
            if(target==0)
                ans.push_back(v);
            return;
        }
        
        if(candidates[idx]<=target)
        {
            v.push_back(candidates[idx]);
             findall(idx,candidates,target-candidates[idx],v,ans);
            v.pop_back();
        }
           findall(idx+1,candidates,target,v,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        findall(0,candidates,target,v,ans);
        return ans;
    }
};