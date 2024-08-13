class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc, int color,int old)
    {
          int rows = image.size();
        int cols = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
               while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int newR = r + x[i];
                int newC = c + y[i];
                
                if (newR >= 0 && newR < rows && newC >= 0 && newC < cols &&
                    image[newR][newC] == old && image[newR][newC] != color) {
                    image[newR][newC] = color;
                    q.push({newR, newC});
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        bfs(image,sr,sc,color,old);
            return image;
    }
};