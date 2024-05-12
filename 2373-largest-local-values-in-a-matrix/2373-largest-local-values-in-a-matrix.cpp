#include <vector>
#include <climits> // for INT_MIN
using namespace std;

class Solution {
public:
    int findMax(vector<vector<int>>& grid, int i, int j) {
        int x_directions[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int y_directions[] = {1, 1, 0, -1, -1, -1, 0, 1};

        int maxi = grid[i][j]; // Initialize with current cell value
        for (int k = 0; k < 8; k++) {
            int x = i + x_directions[k];
            int y = j + y_directions[k];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {
                if (grid[x][y] >= maxi)
                    maxi = grid[x][y];
            }
        }
        return maxi;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>(grid[0].size() - 2, -1));
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[0].size() - 1; j++) {
                ans[i - 1][j - 1] = findMax(grid, i, j);
            }
        }
        return ans;
    }
};
