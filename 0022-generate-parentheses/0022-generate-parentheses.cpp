class Solution {
public:
    void rec(string s,vector<string>& ans,int open,int close)
    {
        if(close<open)
        return; 

        if(open==0 && close==0)
        {
            ans.push_back(s);
            return;
        }

        // if(open==0)
        // rec(s+')',ans,open,close-1);

        // else if(open==close)
        // rec(s+'(',ans,open-1,close);

         if (open > 0)
            rec(s + '(', ans, open - 1, close);

        if (close > 0)
            rec(s + ')', ans, open, close - 1);
    }
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        rec(s,ans,n,n);
        return ans;
    }
};