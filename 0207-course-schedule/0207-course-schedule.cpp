class Solution {
public:
  
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int,int> indegree;
        for (auto& pre : prerequisites) {
            adjList[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
            
        }
         queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        
        vector<int> courses;
        
        while (!q.empty()) {  // Corrected the condition here
            int node=q.front();
            q.pop();
            courses.push_back(node);
            for (auto it : adjList[node]) {
               indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
                
                }
            }
        
       if(courses.size()==numCourses)
           return true;
        else
        return false;
        
        
    }
};
