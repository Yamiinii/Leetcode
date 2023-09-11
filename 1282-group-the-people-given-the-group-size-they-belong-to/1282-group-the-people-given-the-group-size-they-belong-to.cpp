class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> groups;
        vector<vector<int>> ans;
        
        // Populate the groups map
        for (int i = 0; i < groupSizes.size(); i++) {
            int size = groupSizes[i];
            groups[size].push_back(i);
        }
        
        // Iterate through the groups and create subgroups
        for (auto& entry : groups) {
            int groupSize = entry.first;
            vector<int>& group = entry.second;
            
            for (int i = 0; i < group.size(); i += groupSize) {
                vector<int> subgroup(group.begin() + i, group.begin() + i + groupSize);
                ans.push_back(subgroup);
            }
        }
        
        return ans;
    }
};
