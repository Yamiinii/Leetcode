class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int time=0;
        int fresh=0;
        queue<pair<int,int>> q;
       for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};

        while(!q.empty() && fresh>0)
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto [dx,dy]=q.front();
                q.pop();
                for(int j=0;j<4;j++)
                {
                    int xi=dx+x[j];
                    int yi=dy+y[j];

                    if(xi>=0 && xi<n && yi>=0 && yi<m && grid[xi][yi]==1)
                    {
                        q.push({xi,yi});
                        grid[xi][yi]=2;
                        fresh--;
                    }

                }

            }
                time++;
        }

        return fresh==0?time:-1;
    }
};