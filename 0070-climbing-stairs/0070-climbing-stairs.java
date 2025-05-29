class Solution {
    public int climbStairs(int n) {
        if(n==0||n==1||n==2)
        return n;

        List<Integer> dp=new ArrayList<>(Collections.nCopies(n+1,-1));
        dp.set(0,0);
        dp.set(1,1);
        dp.set(2,2);

        for(int i=3;i<=n;i++)
        {
            int val=dp.get(i-1)+dp.get(i-2);
            dp.set(i,val);
        }

        return dp.get(n);
    }
}