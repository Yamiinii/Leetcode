class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto it:prerequisites)
        {
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++)
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
            for(auto it:adj[front])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        if(topo.size() == numCourses)
            return topo;
        else
            return vector<int> {};
        
    }
};