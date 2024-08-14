class Solution {
public:
    double bfs(string src,string dest, unordered_map<string,vector<pair<string,double>>> &adj)
    {
        queue<pair<string,double>> q;
        q.push({src,1.0});
        unordered_map<string,int> vis;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto x=q.front();
                q.pop();
                string node=x.first;
                double d=x.second;
                vis[node]++;
                if(node==dest)
                    return d;
                for(auto & c:adj[node])
                {
                    if(vis.find(c.first)==vis.end())
                        q.push({c.first,d*c.second});
                }
            }
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& a, vector<double>& b, vector<vector<string>>& q) {
        unordered_map<string,vector<pair<string,double>>> adj;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            adj[a[i][0]].push_back({a[i][1],b[i]});
            adj[a[i][1]].push_back({a[i][0],1/b[i]});
        }
        
        vector<double> ans;
        
        for(auto& x:q)
        {
            if(adj.find(x[0])==adj.end() || adj.find(x[1])==adj.end())
                ans.push_back(-1);
            else
                ans.push_back(bfs(x[0],x[1],adj));
        }
        
        return ans;
        
    }
};