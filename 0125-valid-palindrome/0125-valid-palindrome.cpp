class Solution {
public:
    bool valid(string &s,  int i) {
        int n = s.length();
        if (i >= n / 2)
            return true;
       else if (s[i] != s[n - i - 1])
            return false;
        return valid(s, i + 1);
    }
    
    bool isPalindrome(string s) {
      string sol;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                sol.push_back(tolower(s[i]));
            else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
                sol.push_back(s[i]);
        }
        
        return valid(sol, 0);

    }
};