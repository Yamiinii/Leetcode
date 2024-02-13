class Solution {
public:
    bool ispalindrome(string s)
    {
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[s.size()-i-1])
                return false;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            if(ispalindrome(words[i]))
                return words[i];
        }
        return "";
    }
};