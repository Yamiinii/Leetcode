class Solution {
public:
    
    bool checkPalindrome(string &s)
    {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    void Partition(vector<vector<string> >& res, string& s,
                   int idx, vector<string>& curr)
    {
        if(idx==s.size())
           { res.push_back(curr);
            return;}
        
        string t;
        for(int i=idx;i<s.size();i++)
        {
            t.push_back(s[i]);
            if(checkPalindrome(t))
            {
                curr.push_back(t);
                Partition(res,s,i+1,curr);
                curr.pop_back();
            }
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
      int idx=0;
         vector<vector<string> > res;
        vector<string> curr;
        Partition(res,s,idx,curr);
        return res;
    }
};