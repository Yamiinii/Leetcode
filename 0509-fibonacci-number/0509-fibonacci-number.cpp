class Solution {
    int dp[31];
public:
    int fib(int n) {
        
        if(n<=0)
            return 0;
        else if(n==1)
            return 1;
        if(dp[n]!=0)
            return dp[n];
        return dp[n]=fib(n-1)+fib(n-2);
    }
};