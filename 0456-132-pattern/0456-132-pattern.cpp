#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<pair<int, int>> s; // pair {num, minLeft}, mono decreasing
        int curMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            while (!s.empty() && nums[i] >= s.top().first) {
                s.pop();
            }
            if (!s.empty() && nums[i] > s.top().second) {
                return true;
            }
            s.push({nums[i], curMin});
            curMin = min(curMin, nums[i]);
        }

        return false;
    }
};
