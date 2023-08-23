class Solution {
public:
    
  void  dfs(vector<vector<int>>& image, int sr, int sc, int color,int in_color)
    {
            image[sr][sc]=color;
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        for(int i=0;i<4;i++)
        {
            int nx=sr+x[i];
            int ny=sc+y[i];
            if (nx >= 0 && nx < image.size() && ny >= 0 && ny < image[0].size() && image[nx][ny] == in_color && image[nx][ny] != color)

               dfs(image,nx,ny,color,in_color); 
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int in_color=image[sr][sc];
        vector<vector<int>> ans=image;
        dfs(ans,sr,sc,color,in_color);
        return ans;
    }
};