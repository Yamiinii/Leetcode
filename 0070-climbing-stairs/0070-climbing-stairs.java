class Solution {
    public int rec(int n,List<Integer> dp)
    {
        if(dp.get(n)!=-1)
        return dp.get(n);

        int result=rec(n-1,dp)+rec(n-2,dp);
        dp.set(n,result);
        return result;

    }

    public int climbStairs(int n) {
        List<Integer> dp = new ArrayList<>(Collections.nCopies(n + 1, -1));

        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        dp.set(0, 0);
        dp.set(1, 1);
        dp.set(2, 2);
        return rec(n,dp);
    }
}