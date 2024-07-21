class Solution {
public:
    string removeDuplicates(string s) {
        //some stack approach is also there
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(ans.size()>0)
            {
                if(ans[ans.size()-1]==s[i])
                {
                    ans.pop_back();
                }
                else
                    ans.push_back(s[i]);
            }
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};