class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        int current_sum=0;
        int cnt=0;
        
        mpp[0]=1;
        //this is because when the sum matches the k then k-k=0
        
        for(int i=0;i<n;i++)
        {
            current_sum+=nums[i];
            if(mpp.find(current_sum-k)!=mpp.end())
                cnt+=mpp[current_sum-k];
            
            mpp[current_sum]++;
        }
        return cnt;
    }
};