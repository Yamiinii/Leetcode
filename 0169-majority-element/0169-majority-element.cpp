class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int maxCount = 0;
        int majorityElement = 0;

        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
            if (mpp[nums[i]] > maxCount) {
                maxCount = mpp[nums[i]];
                majorityElement = nums[i];
            }
        }

        return majorityElement;
    }
};
