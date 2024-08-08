class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& curr,  vector<vector<int>> &ans,vector<bool>& visited,int i,int n)
    {
        if(i==n)
        {
            ans.push_back(curr);
            return;
        }
        
        for(int j=0;j<n;j++)
        {
        if (visited[j]) continue; // Skip if already visited
            
            curr.push_back(nums[j]);
            visited[j] = true;

            // Recurse with the current element included
                    backtrack(nums,curr,ans,visited,i+1,n);

            // Backtrack: remove the last element and mark it as unvisited
            curr.pop_back();
            visited[j] = false;
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        int n=nums.size();
         vector<bool> visited(nums.size(), false);
        backtrack(nums,curr,ans,visited,0,n);
        return ans;
    }
};