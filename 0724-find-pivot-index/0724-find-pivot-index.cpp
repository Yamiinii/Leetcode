class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = 0;
        for(int i=0;i<nums.size();i++)
            rightSum+=nums[i];
        int leftSum = 0;
        for (int idx = 0; idx < nums.size(); idx++) {
            rightSum -= nums[idx];
            if (leftSum == rightSum)
                return idx;   
            leftSum += nums[idx];
        }
        return -1;      
    }
};
