#include <algorithm>  // For std::transform
#include <cctype>     // For std::tolower
#include <string>
class Solution {
public:
    int count(string s)
    {   int ans=0;
            for(auto ch:s)
            {
                if (std::tolower(ch) == 'a' || std::tolower(ch) == 'e' || std::tolower(ch) == 'i' || std::tolower(ch) == 'o' || std::tolower(ch) == 'u')
                    ans++;
            }
     return ans;
    }
    
    bool halvesAreAlike(string s) {

        int n=s.size();
        string s1;
        string s2;
        for(int i=0;i<n/2;i++)
        {
            s1+=s[i];
        }
          for(int i=n/2;i<n;i++)
        {
            s2+=s[i];
        }
        
        int n1=count(s1);
        int n2=count(s2);
        return n1==n2;
    }
};