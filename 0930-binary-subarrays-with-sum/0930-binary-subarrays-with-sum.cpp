class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sum=0;
        int ways=0;
        for(auto it:nums)
        {
            sum+=it;
            if(mpp.find(sum - goal)!=mpp.end())
                ways+=mpp[sum - goal];
            mpp[sum]++;
        }
        
        return ways;
    }
};