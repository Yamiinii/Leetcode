class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> v;

        // Check if the size of the array is a multiple of 3
        if (n % 3 != 0)
            return v;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i += 3) {
            for (int j = 1; j < 3 && i + j < n; j++) {
                if (nums[i + j] - nums[i + j - 1] > k || (j > 1 && nums[i + j] - nums[i + j - 2] > k)) {
                    // If the condition fails, return an empty vector
                    return v;
                }
            }
        }

        for (int i = 0; i < n; i += 3) {
            vector<int> v1;

            for (int j = 0; j < 3 && i + j < n; j++) {
                v1.push_back(nums[i + j]);
            }

            // If the condition is satisfied, add the vector to the result
            v.push_back(v1);
        }

        return v;
    }
};
