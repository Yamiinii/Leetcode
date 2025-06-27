class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string s;
        string curr=strs[0];
        string last=strs[n-1];
        int sz = min(curr.size(), last.size());
        for(int i=0;i<sz;i++)
        {
            if(curr[i]==last[i])
            s+=curr[i];
            else
            break;
        }

        return s;
    }
};