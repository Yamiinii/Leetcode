class Solution {
public:
    int rec(vector<int>& days, vector<int>& costs,int i,vector<int> &dp)
    {
        if(i>=days.size())
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        int cost=0;
        //one day pass
        int oneDay=costs[0]+rec(days,costs,i+1,dp);

        //two days pass
        int idx=i;
        while(idx<days.size() && days[idx]<days[i]+7)
        idx++;
        int sevenDay=costs[1]+rec(days,costs,idx,dp);

        //30 days pass
        idx=i;
        while(idx<days.size() && days[idx]<days[i]+30)
        idx++;
        int thirtyDay=costs[2]+rec(days,costs,idx,dp);

        cost= std::min(oneDay, std::min(sevenDay, thirtyDay));

        return dp[i]=cost;

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return rec(days,costs,0,dp);
    }
};