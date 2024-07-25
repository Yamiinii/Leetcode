class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        stack<char> st1;
        string s1="";
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i]!='*')
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
        }
        while(!st.empty())
        {
            st1.push(st.top());
            st.pop();
        }

        while(!st1.empty())
        {
            s1 += st1.top();
            st1.pop();
        }
        
        return s1;
    }
};