class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return 0;
        vector<vector<int>> dp(n,vector<int> (n,0));
        unordered_map<long,vector<int>> mpp;
        
        for(int i=0;i<n;i++)
        {
            long temp=nums[i];
            if(!mpp.count(temp))
            {
                mpp[temp]=vector<int>();
            }
            
            mpp[temp].push_back(i);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //a is the prev element before nums[i] and nums[j] so nums[i]+nums[i]-nums[j]
                long a=2L*nums[i]-nums[j];
                if(mpp.count(a))
                {
                    for(int k:mpp[a])
                    {

                        if(k<i)
                            dp[i][j]+=dp[k][i]+1;
                        else
                            break;
                    }
                }
                sum+=dp[i][j];
            }
        }
        
        return sum;
        
    }
};