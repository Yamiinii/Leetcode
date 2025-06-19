class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0 || n==1)
        return n;
        int front=0;
        int back=0;
        int maxi=1;
        unordered_map<char,int> mpp;
        mpp[s[0]]++;
        while(front<=back && back<n-1)
        {
            back++;
            mpp[s[back]]++;
            // don't use mpp[back] it's s[back]
            while(mpp[s[back]]>1)
            {
                mpp[s[front]]--;
                front++;
                //silly mistake exchanged both
            }

            maxi=max(maxi,back-front+1);
        }
        return maxi;
    }
};