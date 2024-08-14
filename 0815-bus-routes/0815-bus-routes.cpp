class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)
            return 0;
       vector<vector<int>> v(1e6+1);
        for(int i=0;i<routes.size();i++)
        {
            for(int j=0;j<routes[i].size();j++)
            {
                v[routes[i][j]].push_back(i);
            }
        }
        
        queue<int> q;
        for(int it:v[source])
            q.push(it);
        
        vector<int> visitedstation(1e6+1);
        vector<int> visitedbuses(1e6+1);
        visitedstation[source]=1;
        bool reached=false;
        int cnt=0;
        while(!q.empty())
        {
            int size=q.size();
            cnt++;
            while(size--)
            {
                int front=q.front();
                q.pop();
                for(int station:routes[front])
                {
                    if(station==target)
                    {
                        reached=true;
                        return cnt;
                    }
                    if(visitedstation[station]==0)
                    {
                        for(int bus:v[station])
                        {
                            if(visitedbuses[bus]==0)
                            {
                                q.push(bus);
                                visitedbuses[bus]=1;
                            }
                        }
                        visitedstation[station]=1;
                    }
                }
            }
        }
        
        return reached==true?cnt:-1;
    }
};