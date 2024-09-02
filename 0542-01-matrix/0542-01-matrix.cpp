class Solution {
public:
 

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    // Initialize the visited matrix and distance matrix
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> ans(n, vector<int>(m, INT_MAX)); // Use INT_MAX for initial distances

    queue<pair<pair<int, int>, int>> q;

    // Enqueue all cells with 1s and mark their distance as 0
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 0) {
                visited[i][j] = true;
                ans[i][j] = 0; // Distance to itself is 0
                q.push({{i, j}, 0});
            } else {
                ans[i][j] = INT_MAX; // Initialize distances to a large number
            }
        }
    }

    // Directions for moving in 4 directions (up, down, left, right)
    vector<int> dRow = {1, -1, 0, 0};
    vector<int> dCol = {0, 0, 1, -1};

    // Perform BFS
    while (!q.empty()) {
        auto [cell, dist] = q.front();
        q.pop();

        int row = cell.first;
        int col = cell.second;

        // Explore all 4 possible directions
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            // Check if the new position is within bounds and not visited
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                !visited[newRow][newCol] && ans[newRow][newCol] > dist + 1) {
                visited[newRow][newCol] = true;
                ans[newRow][newCol] = dist + 1; // Update the distance
                q.push({{newRow, newCol}, dist + 1}); // Enqueue the new position with updated distance
            }
        }
    }

    return ans;
}

};