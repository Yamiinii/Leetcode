class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int n=s.size();
        int ans=0;
        unordered_map<char,int>mpp;
        while(right<n)
        {
            if(mpp.count(s[right]) == 0  ||mpp[s[right]]<left)
            {
                mpp[s[right]]=right;
                ans=max(ans,right-left+1);
                
            }
            else
            {
                left=mpp[s[right]]+1;
                mpp[s[right]]=right;
            }
            right++;
        }
        return ans;
    }
};