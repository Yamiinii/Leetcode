class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        //sum=0
        mpp[0]=1;
        int curr_sum=0;
        int cnt=0;
        for(auto i:nums)
        {
            curr_sum+=i;
            if(mpp.find(curr_sum-k)!=mpp.end())
            {
                cnt+=mpp[curr_sum-k];
            }
            mpp[curr_sum]++;
        }

        return cnt;
    }
};