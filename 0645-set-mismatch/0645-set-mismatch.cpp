#include <vector>
#include <map>

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> mpp;
        
        // Count the occurrences of each number
        for(int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }

        vector<int> v;

        // Find the repeated number
        for(auto& entry : mpp) {
            if(entry.second > 1) {
                v.push_back(entry.first);
                break;  // Once you find the repeated number, exit the loop
            }
        }

        // Find the missing number
        for(int i = 1; i <= nums.size(); i++) {
            if(mpp.find(i) == mpp.end()) {
                v.push_back(i);
                break;  // Once you find the missing number, exit the loop
            }
        }

        return v;
    }
};
