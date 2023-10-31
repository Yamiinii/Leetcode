class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        long long sum = 0;
        long long ans = INT_MIN;

        unordered_map<int, int> unique_ele;

        while (end < nums.size()) {
            if (unique_ele.count(nums[end]) == 0) {
                unique_ele[nums[end]]++;
                sum += nums[end];

                if (end - start + 1 < k) {
                    end++;
                } else if (end - start + 1 == k) {
                    ans = max(sum, ans);
                    sum -= nums[start];
                    unique_ele[nums[start]]--;

                    if (unique_ele[nums[start]] == 0) {
                        unique_ele.erase(nums[start]);
                    }
                    start++;
                    end++;
                }
            } else {
                unique_ele[nums[start]]--;
                if (unique_ele[nums[start]] == 0) {
                    unique_ele.erase(nums[start]);
                }
                sum -= nums[start];
                start++;
            }
        }
        if(ans!=INT_MIN)
        return ans;
        else
            return 0;
    }
};
