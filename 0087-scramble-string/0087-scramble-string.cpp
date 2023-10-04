class Solution {
    unordered_map<string,bool> mpp;
public:
    bool solve(string s1, string s2)
    {
        if(s1.compare(s2)==0)
            return true;
        
        if(s1.length()<=1)
         
            return false;
       string key = s1 + " " + s2;
	if (mpp.find(key) != mpp.end()) // if we did not found the and travesed upto end of the map 
		return mpp[key];
        bool flag=false;
        int n=s1.length();
        for(int i=1;i<=s1.length()-1;i++)
        {
            if((solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i),s2.substr(0,n-i))) ||
              (solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i),s2.substr(i))))
               { flag=true;
            break;}
        }
        return mpp[key]=flag;
    }
    
    bool isScramble(string s1, string s2) {
        mpp.clear();
        if(s1.length()!=s2.length())
            return false;
        return solve(s1,s2);
    }
};