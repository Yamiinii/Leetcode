class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V=adj.size();
        vector<int> adjRev[V];
	   vector<int> indegree(V, 0);
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
                adjRev[it].push_back(i);
	            indegree[i]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	    }
	    
	    vector<int> topo;
	    while(!q.empty())
	    {
	        int front=q.front();
	        q.pop();
	        topo.push_back(front);
	        
	        for(auto it:adjRev[front])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
        sort(topo.begin(),topo.end());
	    return topo;
        
    }
};