class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       
        int r=mat.size();
        int c=mat[0].size();
         vector<vector<int>> ans(r,vector<int> (c,0));
         vector<vector<int>> visited(r,vector<int> (c,0));
        queue <pair<pair<int,int>,int>> q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(mat[i][j]==0)
                {
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
                else
                    visited[i][j]=0;
            }
        }
        int x[4]={1,-1,0,0};
        int y[4]={0,0,-1,1};
        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
             q.pop();
            ans[i][j]=dist;
            for(int k=0;k<4;k++)
            {
               int nx=i+x[k];
                int ny=j+y[k];
                if(nx>=0 && nx<r && ny>=0 && ny<c && visited[nx][ny]==0)
                {
                    visited[nx][ny]=1;
                    q.push({{nx,ny},dist+1});
                }
            }
        }
        return ans;
        
    }
};