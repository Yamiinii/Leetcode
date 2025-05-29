class Solution {
public:
    int rec(int n,vector<int> & dp)
    {
        if(n==1||n==2||n==0)
        return dp[n]=n;

        if(dp[n]!=-1)
        return dp[n];

        return dp[n]=rec(n-1,dp)+rec(n-2,dp);
        //once we come to these stairs only one way is there
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // dp[0]=0;
        // dp[1]=1;
        // dp[2]=2;
        //what if n=1 dp[2] won't exist
        return rec(n,dp);
    }
};