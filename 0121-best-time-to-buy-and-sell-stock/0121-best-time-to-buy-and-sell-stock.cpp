class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(prices[i]<mini)
            {
                mini=prices[i];
            }
            else
            {
                int profit=prices[i]-mini;
                maxi=max(maxi,profit);
            }

        }

        return maxi;
    }
};