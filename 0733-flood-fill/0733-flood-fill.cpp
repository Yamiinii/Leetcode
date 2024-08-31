class Solution {
public:
void dfs(vector<vector<int>>& image, int sr, int sc, int color, int org) {
        // Base case to stop recursion
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != org) {
            return;
        }
        
        // Color the current cell
        image[sr][sc] = color;

        // Define the directions for 4-neighbor cells
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        
        // Recurse for all 4 adjacent cells
        for (int k = 0; k < 4; k++) {
            int xi = sr + x[k];
            int yi = sc + y[k];
            
            // Recursive DFS call
            dfs(image, xi, yi, color, org);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
  int org = image[sr][sc];
        if (org != color) { // Check if the color is different to avoid unnecessary operations
            dfs(image, sr, sc, color, org);
        }
        return image;
    }
};