class Solution {
    public int maxProfit(int[] prices) {
        int mini=prices[0];
        int maxi=0;
        for(int i=1;i<prices.length;i++)
        {
            if(prices[i]<mini)
            mini=prices[i];

            maxi=Math.max(maxi,prices[i]-mini);
        }

        return maxi;
    }
}