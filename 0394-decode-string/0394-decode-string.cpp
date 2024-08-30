class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            string substr;
            if(s[i]!=']')
                st.push(s[i]);
            else
            {
                while(!st.empty() && st.top()!='[')
                {
                    substr=st.top()+substr;
                    st.pop();
                }
                st.pop();
                string num;
                while(!st.empty() && isdigit(st.top()))
                {
                    num=st.top()+num;
                    st.pop();
                }
                
                int num2=stoi(num);
                for(int j=0;j<num2;j++)
                {
                   for (char ch : substr) {
                        st.push(ch);
                    }
                }
            }
            
            
        }
        
         while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};