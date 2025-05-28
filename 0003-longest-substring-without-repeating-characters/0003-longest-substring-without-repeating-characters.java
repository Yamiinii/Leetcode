class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        if(n==0 ||n==1)
        return n;
        int front=0;
        int back=0;
        int maxi=1;
        HashMap<Character,Integer> mpp=new HashMap<>();
        mpp.put(s.charAt(0),1);
//when I added front <=back not needed
        while(back<n-1)
        {
            back++;
            char c=s.charAt(back);
            mpp.put(c,mpp.getOrDefault(c,0)+1);
            // This looks up the value for key c in the map.If c exists in the    map, it returns the current count (an Integer).If c does not exist it returns the default value, which is 0.
            while(mpp.get(c)>1)
            {
                char frontchar=s.charAt(front);
                mpp.put(frontchar,mpp.get(frontchar)-1);
                front++;
            }
            maxi=Math.max(maxi,back-front+1);
        }

        return maxi;
    }
}