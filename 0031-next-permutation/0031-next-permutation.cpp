class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int dip=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                dip=i;
                break;
            }
        }
        
        if(dip==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        int mini = nums[dip + 1];
        int number = dip + 1;
        
        for (int idx = dip + 1; idx < n; idx++) {
            if (nums[idx] > nums[dip] && nums[idx] < mini) {
                mini = nums[idx];
                number = idx;
            }
        }
        
        swap(nums[dip],nums[number]);
        
        sort(nums.begin()+dip+1,nums.end());
    }
};