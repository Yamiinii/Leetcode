class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mpp;
        int left,right=0;
        int maxi=0;
        while(right<n)
        {
            char ch=s[right];
            mpp[ch]++;
            while(mpp[ch]>1)
            {
                mpp[s[left]]--;
                left++;
            }
            maxi=max(maxi,right-left+1);
            right++;
        }
      
        return maxi;
    }
};