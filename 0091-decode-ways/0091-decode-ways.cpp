class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if (n == 0 || s[0] == '0')
            return 0;
        
        vector<int> dp(n+1,0);
        // dp[0]=s[0]=='0'?0:1;
        dp[0] = 1;  // Empty string
        dp[1] = 1;  // First char is valid (already checked != '0')

        for(int i=2;i<=n;i++)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];
            //When i == n, s[i] will access out-of-bounds memory.
            //if(s[i-1]=='1' || (s[i-1]=='2' && s[i]>='0' && s[i]<='6'))
            //dp[i]+=dp[i-2];
            int twoDigit = stoi(s.substr(i - 2, 2));
if (twoDigit >= 10 && twoDigit <= 26)
    dp[i] += dp[i - 2];


        }

        return dp[n];
        
    }
};