class Solution {
    public int myAtoi(String s) {
        s=s.trim();
        int i=0;
        int n=s.length();
        boolean pos=true;
        if(i<n && (s.charAt(i)=='+' || s.charAt(i)=='-'))
        {
            pos=(s.charAt(i)=='+');
            i++;
        }

        while(i<n && s.charAt(i)=='0')
        {
            i++;
        }

        long result=0;
        while(i<n && Character.isDigit(s.charAt(i)))
        {
            result=result*10 + (s.charAt(i)-'0');
            if(pos && result>Integer.MAX_VALUE)
            return Integer.MAX_VALUE;
            if(!pos && -result<Integer.MIN_VALUE)
            return Integer.MIN_VALUE;
            i++;
        }

        return pos?(int)result:(int)-result;
    }
}