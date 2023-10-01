class Solution {
public:
            //DFS
    bool dfs(vector<vector<int>>& graph,int i,vector<int> &coloured,int color)
    {
        coloured[i]=color;
        for(auto it:graph[i])
        {if(coloured[it]==-1)
               { if(dfs(graph,it,coloured,1-color)==false)
                    return false;
               } else if(coloured[it]==coloured[i])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        vector<int> coloured(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(coloured[i]==-1)
               { if(dfs(graph,i,coloured,1)==false)
                    return false;}
            
        }
        return true;
        
    }
};