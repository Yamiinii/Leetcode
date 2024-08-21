#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    // Recursive helper function to generate subsets
    void rec(const std::vector<int>& arr, int idx, std::vector<int>& temp, std::set<std::vector<int>>& v) {
        if (idx == arr.size()) {
            v.insert(temp);  // Insert the current subset into the set
            return;
        }

        // Include the current element
        temp.push_back(arr[idx]);
        rec(arr, idx + 1, temp, v);

        // Exclude the current element
        temp.pop_back();
        rec(arr, idx + 1, temp, v);
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& arr) {
        std::set<std::vector<int>> v;
        std::vector<int> temp;
        
        // Sort the array to handle duplicates
        std::sort(arr.begin(), arr.end());
        
        rec(arr, 0, temp, v);
        
        // Convert the set of subsets to a vector
        std::vector<std::vector<int>> ans(v.begin(), v.end());
        return ans;
    }
};
