class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)
            return 0;
     vector<vector<int>> mpp(1e6+1);
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                mpp[routes[i][j]].push_back(i);
            }
        }
        
        queue<int> q;
        for(auto it:mpp[source])
            q.push(it);
        int cnt=0;
        bool reached=false;
        vector<bool> visitedstation(1e5+1);
        vector<bool> visitedbuses(1e5+1);
        visitedstation[source]=true;
        while(!q.empty())
        {
            int sz=q.size();
            cnt++;
            while(sz--)
            {
                int front=q.front();
                q.pop();
                for(auto it:routes[front])
                {
                    if(it==target)
                    {
                        reached=true;
                        return cnt;
                    }
                    
                     if(visitedstation[it]==0)
                    {
                        for(int bus:mpp[it])
                        {
                            if(visitedbuses[bus]==0)
                            {
                                q.push(bus);
                                visitedbuses[bus]=1;
                            }
                        }
                        visitedstation[it]=1;
                    }
                }
            }
        }
        
        return reached==true?cnt:-1;
    }
};