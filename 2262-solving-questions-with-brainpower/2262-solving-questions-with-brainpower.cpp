class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            long long jump=i+questions[i][1]+1;
            long long take=questions[i][0];
            if(jump<n)
            {
                take+=dp[jump];
            }

            dp[i]=max(take,dp[i+1]);
        }

        return dp[0];
    }
};