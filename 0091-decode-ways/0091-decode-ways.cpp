class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (n == 0 || s[0] == '0') return 0;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]!='0')
            dp[i]+=dp[i-1];

            //if (s[i-1]=='1' || (s[i-1]=='2' && s[i]>='0' && s[i]<='6'))
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '0' && s[i - 1] <= '6'))
            dp[i]+=dp[i-2];
        }

        return dp[n];
    }
};