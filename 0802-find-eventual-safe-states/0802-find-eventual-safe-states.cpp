class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int node,vector<int> &visited,vector<int> &pathVisit,vector<int> &check)
             {
                visited[node]=1;
                pathVisit[node]=1;
        check[node]=0;
                for(auto it:graph[node])
                {
                    if(!visited[it])
                    {
                        if(dfs(graph,it,visited,pathVisit,check)==true)
                        {
                            check[node]=0;
                            return true;
                        }
                    }
                    else if(pathVisit[it])
                    {
                          check[node]=0;
                            return true;
                    }
                }
        check[node]=1;
        pathVisit[node]=0;
        return false;
             }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> pathVisit(n,0);
        vector<int> check(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            dfs(graph,i,visited,pathVisit,check);
        }
        for(int i=0;i<n;i++)
        {
            if(check[i]==1)
                ans.push_back(i);
        }
        return ans;
    }
};