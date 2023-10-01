class Solution {
public:
    string reverse(string s)
    {

        string word="";
        for(int i=s.size()-1;i>=0;i--)
        {
            word+=s[i];
        }
        return word;
    }
    
    string reverseWords(string s) {
        istringstream ss(s);
 
        string word;
        string ans="";
        bool firstword=true;
        while (ss >> word)
        {
            word=reverse(word);
            if(!firstword)
                ans+=" ";
            
            ans+=word;
            firstword=false;
            
        }
        return ans;
    }
};