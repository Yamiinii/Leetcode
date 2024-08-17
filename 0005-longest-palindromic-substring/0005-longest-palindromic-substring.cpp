class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return "";
        if(n==1)
            return s;
        
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        
        int start=0;
        int maxlen=1;
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                start=i;
                maxlen=2;
            }
        }
        
        for(int len=3;len<=n;len++)
        {
            for(int i=0;i<=n-len;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j]=true;
                    if(len>maxlen)
                {start=i;
                maxlen=len;}
                }
            }
        }
        
        return s.substr(start,maxlen);
    }
};