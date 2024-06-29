class Solution {
public:
    void dfs(int node,vector<bool> &visited,vector<vector<int>>& adj,vector<vector<int>>& ans,int parent)
    {
            visited[node]=true;
             
            for(auto it:adj[node])
            {
                if(!visited[it])
                {   ans[it].push_back(parent);
                    dfs(it,visited,adj,ans,parent);
                }
            }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<vector<int>> ans(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i=0;i<n;i++)
        {
          vector<bool> visited(n,false);
            dfs(i,visited,adj,ans,i);
        }
        for(int i=0;i<n;i++)
        {
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};