class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
        unordered_map<char,int>mpp;
        int left=0;
        int maxLength=0;
        for(int right=0;right<n;right++)
        {
            if (mpp.count(s[right]) == 0 || mpp[s[right]] < left) {
                mpp[s[right]]=right;
                maxLength = max(maxLength, right - left + 1);
            }
            else
            {
                left = mpp[s[right]] + 1;
                mpp[s[right]] = right;
            }
            
        }
                return maxLength;
    }
};
