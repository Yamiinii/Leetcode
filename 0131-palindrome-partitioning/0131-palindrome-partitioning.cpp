class Solution {
public:
    bool isPalindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        
        return true;
    }
    
    void rec(string s,vector<vector<string>>& ans,vector<string> &v,int start)
    {
            if(start==s.size())
            {
                ans.push_back(v);
                return;
            }
        
        for(int end=start;end<s.size();end++)
        {
            if(isPalindrome(s,start,end))
            {
                v.push_back(s.substr(start,end-start+1));
                rec(s,ans,v,end+1);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        rec(s,ans,v,0);
        return ans;
    }
};