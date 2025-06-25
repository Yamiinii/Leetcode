class Solution {
public:
    int rec(string s,int n ,int idx,vector<int> &dp)
    {
        if(idx==n)
        {
           return 1;
        }

        if(s[idx]=='0')
        return 0;

        if(dp[idx]!=-1)
        return dp[idx];

        int ways=0;
        ways+=rec(s,n,idx+1,dp);
        if(idx+1<n)
        {
            if(s[idx]=='1' || (s[idx]=='2' && s[idx+1]>='0' && s[idx+1]<='6'))
            ways+=rec(s,n,idx+2,dp);
        }

        return dp[idx]=ways;
    }

    int numDecodings(string s) {
        int n=s.size();
        if(n<=0)
        return 0;
        // int cnt=0;
        vector<int> dp(n,-1);
        return rec(s,n,0,dp);
        // return cnt;
    }
};