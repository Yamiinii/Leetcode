class Solution {
public:
    int calc(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& visited) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 1;
        }
        if (grid[i][j] == 0) {
            return 1;
        }
        if (visited[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        int perimeter = 0;
        perimeter += calc(grid, i - 1, j, visited);
        perimeter += calc(grid, i + 1, j, visited);
        perimeter += calc(grid, i, j - 1, visited);
        perimeter += calc(grid, i, j + 1, visited);
        return perimeter;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return calc(grid, i, j, visited);
                }
            }
        }
        return 0;
    }
};
