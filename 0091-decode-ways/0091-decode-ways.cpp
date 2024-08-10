class Solution {
public:
    int ways(string s ,vector<int> &dp,int i)
    {
        if(i==s.size())
            return 1;
        if(s.size()==0)
            return 0;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        //considering only a single char
        int ans=ways(s,dp,i+1);
        if(i<s.size()-1 && (s[i]=='1' || s[i]=='2' && s[i+1]<='6'))
            ans+=ways(s,dp,i+2);
        
        return dp[i]=ans;
    }
    
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return ways(s,dp,0);
    }
};