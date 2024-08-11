class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n==k)
            return true;
        if(n<k)
            return false;
        unordered_map<char,int> mpp;
        for(auto charr:s)
        {
            mpp[charr]++;
        }
        int oddcnt=0;
        for(auto it:mpp)
        {
            if(it.second%2!=0)
                oddcnt++;
        }
        return oddcnt<=k;
    }
};