class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int tail=0;
        int ans=0;
        unordered_map<char,int> mpp;
        int head;
        for(head=0;head<s.size();head++)
        {
            while(mpp[s[head]]>0)
                
            {
                ans=max(ans,head-tail);
                mpp[s[tail]]--;
                tail++;
            }
            mpp[s[head]]++;
        }
        //exited the loop that's why head-tail
        return max(ans,head-tail);
    }
};