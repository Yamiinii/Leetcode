class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size();
        int i=0;
        while(i<n)
        {
            while(s[i]==' ') i++;
            if(i>=n) break;
            int j=i+1;
            while(j<n && s[j]!=' ')
            {
                j++;
            }
            string st=s.substr(i,j-i);
            if(ans.size()==0)
                ans=st;
            else
                ans=st+" "+ans;
            
            i=j+1;
        }
        return ans;
    }
};