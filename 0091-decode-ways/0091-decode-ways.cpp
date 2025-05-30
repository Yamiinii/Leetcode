class Solution {
public:
    int rec(string s,int i,vector<int> &dp)
    {
        if(i==s.size())
        return 1;
        //cannot decode 0
        if(s[i]=='0')
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ways=0;
        //for one char
        ways+=rec(s,i+1,dp);
        //I can use dp to calculate one and two char parts also 
        //for two char
        if(i+1<s.size() && (s[i]=='1' || (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6')))
        {
            ways+=rec(s,i+2,dp);
        }

        return dp[i]=ways;
    }

    int numDecodings(string s) {
        int n=s.size();
        if(n==0)
        return 0;
        vector<int> dp(n+1,-1);
        return rec(s,0,dp);
    }
};