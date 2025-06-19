class Solution {
    public boolean isPalindrome(int i,int j,String s,Boolean[][] dp)
    {
        if(i>=j)
        return true;

        if(dp[i][j]!=null)
        return dp[i][j];

        return dp[i][j] = (s.charAt(i) == s.charAt(j)) && isPalindrome(i + 1, j - 1, s, dp);
        
    }

    public String longestPalindrome(String s) {
        int n=s.length();
        if(n<=1)
        return s;
        Boolean[][] dp=new Boolean[n][n];
        int start=0;
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(i,j,s,dp) && (j-i+1>maxi))
                {
                    start=i;
                    maxi=j-i+1;
                }
            }
        }

        return s.substring(start,start+maxi);
    }
}