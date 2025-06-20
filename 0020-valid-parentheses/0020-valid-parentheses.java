class Solution {
    public boolean isValid(String s) {
        Stack<Character> st=new Stack<>();
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s.charAt(i)=='(' || s.charAt(i)=='[' || s.charAt(i)=='{')
            st.push(s.charAt(i));

            else{
                if(st.isEmpty())
                return false;
                //don't write charAt and peek again and again mention as ch and top
                else if(s.charAt(i)==')' && st.peek()=='(' || s.charAt(i)==']' && st.peek()=='[' || s.charAt(i)=='}' && st.peek()=='{')
            st.pop();

                else
                return false;

            }
        }

        return st.isEmpty();
    }
}