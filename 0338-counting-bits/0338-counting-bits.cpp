class Solution {
public:

    int solve(int n,vector<int>&dp)
    {


        if(dp[n]!=-1)
        {
            
            return dp[n];
        }

        int a = 0,b=0;
        if(n%2==0)
        {
            a+=solve(n/2,dp);
            dp[n]=a;
        }
        else
        {
            b+=(1 + solve(n/2,dp));
            dp[n]=b;
        }
    return  dp[n];
    }


    vector<int> countBits(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        if(n!=0)
        {
             dp[1]=1;
        }
       

    for(int i=n; i>=0 ;i--)
    {
         int a =  solve(i,dp);
         dp[i]=a;
    }
     
        return dp;
    }
};