class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            int day=days[i-1];
            //one day 
            int cost1=dp[i-1]+costs[0];

            //two day
            // After the loop:

            // j is the last day not covered by the 7-day pass.

            // So, j + 1 is the first day covered by this 7-day pass.
            int j=i-1;
            while(j>=0 && days[j]>=day-6)
            j--;
            int cost2=dp[j+1]+costs[1];

            //thirty day
            j=i-1;
            while(j>=0 && days[j]>=day-29)
            j--;
            int cost3=dp[j+1]+costs[2];

            dp[i]=min(cost1,min(cost2,cost3));
        }
        return dp[n];
    }
};