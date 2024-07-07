class Solution {
public:
    unordered_map<string,bool> mpp;
    bool solve(string s1, string s2)
    {
        string key=s1+" "+s2;
        
        if(s1==s2)
            return mpp[key]=true;
        //empty string not possible
        int n=s1.length();
        if(n<=1)
            return mpp[key]=false;
        
        if(mpp.find(key)!=mpp.end())
            return mpp[key];
        bool flag=false;
        
    for(int k=1;k<n;k++)
        {
            if((solve(s1.substr(0,k),s2.substr(n-k,k)) && solve(s1.substr(k),s2.substr(0,n-k))) || 
              (solve(s1.substr(0,k),s2.substr(0,k)) && solve(s1.substr(k),s2.substr(k))))
            {
                flag=true;
                break;
            }
        }
        
        return mpp[key]=flag;
        
    }
    
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};