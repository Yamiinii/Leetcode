class Solution {
public:
    bool check(string &s, string &p, int sstart, int pstart)
    {
        int n=s.size();
        int m=p.size();
        if(pstart==m)
        return sstart==n;

        bool first=(sstart < n &&
                          (s[sstart] == p[pstart] || p[pstart] == '.'));

        if(pstart+1<m && p[pstart+1]=='*')
        {
            //ignoring the letters before * and then seeing if after start character matches sstart character
            return (check(s,p,sstart,pstart+2)) ||
            (first && check(s,p,sstart+1,pstart));
        }
        else
        return (first && check(s,p,sstart+1,pstart+1));
    }
    bool isMatch(string s, string p) {
        //if more letters are there in p then it will return false
        //if it is a char or . then simply match
        //if it is * then we cannot see till then next matching letter
        // for ex our s =abbbbb p=a*bb so we cannot just iterate to the last b according to our logic it will match the b on 2nd index and then simply return false
        //so we will check every occurence of the char and try to match the string 
        int n=s.size();
        int m=p.size();
        // if(m>n)
        // return false;
        int sstart=0;
        int pstart=0;
        return check(s,p,sstart,pstart);
        
    }
};