class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int> st;
        int n=as.size();
        for(int i=0;i<n;i++)
        {
            if(as[i]>0)
                st.push(as[i]);
            else
            {
                while(!st.empty() && st.top()>0 && st.top()<abs(as[i]))
                    st.pop();
                
                if(st.empty() || st.top()<0)
                    st.push(as[i]);
                
                else if(st.top()==abs(as[i]))
                        st.pop();
                
            }
        }
                        
        vector<int> ans;
        while(!st.empty())
                        {
                            int top=st.top();
                            st.pop();
                            ans.push_back(top);
                        }
        reverse(ans.begin(),ans.end());
                        return ans;
    }
};