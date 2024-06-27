class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mpp;
        for (auto& edge : edges) {
            mpp[edge[0]]++;
            mpp[edge[1]]++;
        }

        for (auto& pair : mpp) {
            if (pair.second > 1) {
                return pair.first;
            }
        }
        
        return -1; // No center found
    }
};
