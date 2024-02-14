#include <vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        
        // Separate positive and negative numbers
        vector<int> positive;
        vector<int> negative;
        for (int num : nums) {
            if (num >= 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }
        
        // Rearrange the array
        int posIndex = 0, negIndex = 0;
        for (int i = 0; i < result.size(); ++i) {
            if (i % 2 == 0 && posIndex < positive.size()) {
                result[i] = positive[posIndex++];
            } else if (negIndex < negative.size()) {
                result[i] = negative[negIndex++];
            } else {
                result[i] = positive[posIndex++];
            }
        }
        
        return result;
    }
};
