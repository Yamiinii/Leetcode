class Solution {
public:
    long long rec(vector<vector<int>>& questions,vector<long long> & dp,int i)
    {
        if(i>=questions.size())
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        long long ans=0;
        long long take=questions[i][0]+rec(questions,dp,i+questions[i][1]+1);
        long long not_take=rec(questions,dp,i+1);

        ans=max(take,not_take);

        return dp[i]=ans;
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n+1,-1);
        return rec(questions,dp,0);
    }
};