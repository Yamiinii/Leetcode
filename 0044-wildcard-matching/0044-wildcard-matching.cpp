class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true; //empty strings will match

        //now I will see if we s string is empty but there is a * to be matched then it will like the previous one
        for(int j=1;j<=m;j++)
        {
            if(p[j-1]=='*')
            dp[0][j]=dp[0][j-1];
        }

        //now for the complete string
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
                
                else if(p[j-1]=='*')
                dp[i][j]=dp[i-1][j] || dp[i][j-1];
                //first is matching empty string we didn't consider any new letter from j 
                //second is matching complete till now that is s[i-1] keeping * active
            }
        }

        return dp[n][m];
    }
};