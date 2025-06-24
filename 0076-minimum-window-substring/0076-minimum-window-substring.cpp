class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> mpp1;
       int n=s.size();
       int m=t.size();
       for(int i=0;i<m;i++)
       {
        mpp1[t[i]]++;
       }
       int desired=mpp1.size();
       int curr=0;
       unordered_map<char,int> mpp2;
       int left=0;
       int right=0;
       int mini=INT_MAX;
       int start=0;
       while(right<n)
       {
            char c=s[right];
            mpp2[c]++;

            if(mpp1.count(c) && mpp1[c]==mpp2[c])
            curr++;

            while(left<=right && curr==desired)
            {
                if(right-left+1<mini)
                {
                    mini=right-left+1;
                    start=left;
                }

                int ch=s[left];
                mpp2[ch]--;
                if(mpp1.count(ch) && mpp2[ch]<mpp1[ch])
                curr--;

                left++;
            }

            right++;
       }

       return mini==INT_MAX?"":s.substr(start,mini);
    }
};