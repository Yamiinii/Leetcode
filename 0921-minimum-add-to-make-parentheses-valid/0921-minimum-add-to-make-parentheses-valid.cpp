class Solution {
public:
    int minAddToMakeValid(string s) {
       stack<char> st;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push('(');
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    cnt++;
                    continue;
                }
                else if(st.top()=='(')
                    st.pop();
                else
                {
                        cnt++;
                    continue;
                }
                    
            }
        }
        
       cnt += st.size();
        return cnt;
            
    }
};