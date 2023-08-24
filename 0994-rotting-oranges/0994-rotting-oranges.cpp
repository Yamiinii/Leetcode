class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int vis[grid.size()][grid[0].size()];
        int cntfresh = 0;
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
                
                if(grid[i][j] == 1) {
                    cntfresh++;
                }
            }
        }
        
        int time = 0;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        int cnt = 0;
        
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            
            for(int i = 0; i < 4; i++) {
                int nrow = r + x[i];
                int ncol = c + y[i];
                
                if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, t + 1});
                    cnt++;
                }
            }
        }
        
        if(cntfresh != cnt)
           return -1;
           
        return time;
    }
};
