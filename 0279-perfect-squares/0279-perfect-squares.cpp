class Solution {
public:
    // bool issqrt(int n)
    // {
    //     if(n>=0)
    //     {
    //         int s=sqrt(n);
    //         return (s*s)==n;
    //     }

    //     return false;
    // }

    // int rec(int num,int n)
    // {
    //     //first n-1
    //     //yes sqrt then n-sqrt if that is also a sqrt
    //     //no then go for n-2
    //     if(issqrt(n))
    //     {
    //         return 1+issqrt(num-n);
    //     }
    //     else
    //     return rec(num,n-1);
    // }

    // int numSquares(int n) {
    //     // if n is a perfect sq then only 2 number is req
    //     // else we will try to see what is the next perfect sq number 
    //     //for eg 12 is n
    //     // now one before is 9 remaining 3 -> we can't break it as 1+2 1 is a perfect sq but not 2
    //     //moving ahead 4 +4+4 hence the answer is 3
    //     if(issqrt(n))
    //     return 2;

    //     return rec(n,n-1);
    // }
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};