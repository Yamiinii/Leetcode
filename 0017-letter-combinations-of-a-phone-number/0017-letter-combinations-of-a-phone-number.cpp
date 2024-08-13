class Solution {
public:
    void backtrack(int i,string digits,string path,vector<string> &ans, unordered_map<char,string>& mpp)
    {
        if(path.size()==digits.size())
        {
            ans.push_back(path);
            return;
        }
        
         string s = mpp.at(digits[i]);
        for(auto posn:s)
        {
            backtrack(i+1,digits,path+posn,ans,mpp);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string> {};
        
        vector<string> ans;
        string path;
        unordered_map<char,string> mpp=
        {
            {'2',"abc"},{'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        
        backtrack(0,digits,path,ans,mpp);
        return ans;
    }
};