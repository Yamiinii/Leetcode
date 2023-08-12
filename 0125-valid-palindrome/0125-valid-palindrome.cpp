class Solution {
public:
    bool revStr(string& sol, int i){
        int len=sol.length();
        
        if(i>=len/2) return true;
        else if (sol[i]!=sol[len-i-1]) return false;
        return revStr(sol, i+1);
    }

    bool isPalindrome(string s) {
        string sol;

        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z') sol.push_back(tolower(s[i]));
            else if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9') sol.push_back(s[i]);
        }
        return revStr(sol, 0);
    }
};