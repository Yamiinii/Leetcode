class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=0;
            long maxi=0;
        long total=0;
        while(right<n)
        {
            total+=nums[right];
           while(nums[right]*static_cast<long>(right-left+1)>total+k)
            {
                total-=nums[left];
                left++;
            }
                        maxi=max(maxi,static_cast<long>(right-left+1));            right++;
        }
        return static_cast<int>(maxi);
    }
};