class Solution {
public:
    void gen(int n,int opencnt,int closecnt,vector<string>& ans,string temp)
    {
        if(temp.size()==2*n)
        {
            ans.push_back(temp);
            return;
        }
        
        if(opencnt<n)
            gen(n,opencnt+1,closecnt,ans,temp+"(");
        if(closecnt<opencnt)
            gen(n,opencnt,closecnt+1,ans,temp+")");
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n>0)
            gen(n,1,0,ans,"(");
        return ans;
    }
};