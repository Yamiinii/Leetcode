#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& mat, int i, int j, vector<vector<bool>>& visited) {
        // Mark the current cell as visited
        visited[i][j] = true;
        
        // Directions for moving in 4 directions (down, up, right, left)
        vector<int> dRow = {1, -1, 0, 0};
        vector<int> dCol = {0, 0, 1, -1};
        
        // Explore all 4 possible directions
        for (int k = 0; k < 4; ++k) {
            int newRow = i + dRow[k];
            int newCol = j + dCol[k];
            
            if (newRow >= 0 && newRow < mat.size() && newCol >= 0 && newCol < mat[0].size() &&
                !visited[newRow][newCol] && mat[newRow][newCol] == 'O') {
                dfs(mat, newRow, newCol, visited);
            }
        }
    }
    
    void solve(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Start DFS from all boundary 'O's
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && mat[i][j] == 'O' && !visited[i][j]) {
                    dfs(mat, i, j, visited);
                }
            }
        }
        
        // Flip all remaining 'O's to 'X' and convert 'O's marked visited to 'O'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};
