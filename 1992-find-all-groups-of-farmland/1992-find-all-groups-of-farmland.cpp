class Solution {
public:
    void findFarmlandDFS(vector<vector<int>>& land, int start_i, int start_j, int& end_i, int& end_j, vector<vector<bool>>& visited) {
        if (start_i < 0 || start_i >= land.size() || start_j < 0 || start_j >= land[0].size() || land[start_i][start_j] == 0 || visited[start_i][start_j]) {
            return;
        }

        visited[start_i][start_j] = true;

        
        end_i = max(end_i, start_i);
        end_j = max(end_j, start_j);

       
        findFarmlandDFS(land, start_i + 1, start_j, end_i, end_j, visited);
        findFarmlandDFS(land, start_i, start_j + 1, end_i, end_j, visited);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));

        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j] == 1 && !visited[i][j]) {
                    int end_i = i, end_j = j; 
                    findFarmlandDFS(land, i, j, end_i, end_j, visited);
                    ans.push_back({i, j, end_i, end_j}); 
                }
            }
        }

        return ans;
    }
};
