class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        long long maxi=0;
        int left=0;
        int right=0;
        long long curr_sum=0;
        while(right<nums.size() && left<=right)
        {
            //everytime forgetting to write nums
            mpp[nums[right]]++;
            curr_sum+=nums[right];
            while(mpp[nums[right]]>1 || right-left+1>k)
            {
                mpp[nums[left]]--;
                curr_sum-=nums[left];
                left++;
            }
 
            if(right-left+1==k)
            maxi=max(maxi,curr_sum);

            right++;
        }

        return maxi;
    }
};