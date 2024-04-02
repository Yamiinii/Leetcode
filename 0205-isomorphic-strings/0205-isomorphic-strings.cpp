class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m)
            return false;
        unordered_map<char,char> mpp;
for (int i = 0; i < n; i++) {
          
            if (mpp.find(s[i]) != mpp.end() && mpp[s[i]] != t[i])
                return false;

            
            if (mpp.find(s[i]) == mpp.end()) {
                
                for (auto it = mpp.begin(); it != mpp.end(); ++it) {
                    if (it->second == t[i])
                        return false;
                }
               
                mpp[s[i]] = t[i];
            }
        }

        
        return true;
    }
};