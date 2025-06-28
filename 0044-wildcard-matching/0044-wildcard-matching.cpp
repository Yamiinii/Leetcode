class Solution {
public:
    // bool check(string s, string p,int sstart,int pstart,vector<vector<int>>& dp)
    // {
    //     int n=s.size();
    //     int m=p.size();
    //     //string key=to_string(sstart)+','+to_string(pstart);
    //     if(sstart==n && pstart==m)
    //     return true;
    //     //if(sstart==n || pstart==m)
    //     if(pstart==m)
    //     return false;
    // //  if (mpp.find(key) != mpp.end())
    // // return mpp[key];
    // if(dp[sstart][pstart]!=-1)
    // return dp[sstart][pstart];

    //     if (sstart == n) {
    //         // Only valid if all remaining pattern characters are '*'
    //         for (int i = pstart; i < m; ++i) {
    //             if (p[i] != '*') return dp[sstart][pstart]=0;
    //         }
    //         return dp[sstart][pstart]=1;
    //     }
    
    //     if(p[pstart]=='*')
    //     return    dp[sstart][pstart]=check(s,p,sstart+1,pstart,dp) || check(s,p,sstart,pstart+1,dp);
        
    //     else if((s[sstart]==p[pstart] || p[pstart]=='?'))
    //     return    dp[sstart][pstart]=check(s,p,sstart+1,pstart+1,dp);

    //     return    dp[sstart][pstart]=0;
              
    // }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // if(p=="*")
        // return true;
        //unordered_map<string,bool> mpp;
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        //now I will see if we s string is empty but there is a * to be matched then it will like the previous one
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*')
            dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                dp[i][j]=dp[i-1][j-1];
                else if(p[j - 1] == '*')
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else
                dp[i][j]=false;
            }
        }

        return dp[n][m];
    }
};