class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            int num1=nums[i];
            int num2=target-num1;
            if(mpp.find(num2)!=mpp.end())
            {
                return {i,mpp[num2]};
            }
            mpp[num1]=i;
        }
        return vector<int> {-1,-1};
    }
};