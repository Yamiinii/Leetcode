class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int ans=0;
        for(char c='A';c<='Z';c++)
        {
            int i=0,j=0;
            int cnt=0;
            while(j<n)
            {
                if(s[j]!=c)
                    cnt++;
                while(cnt>k)
                {
                    ans=max(ans,j-i);
                    if(s[i]!=c)
                        cnt--;
                    i++;
                }
                
                j++;
            }
            
            ans=max(j-i,ans);
        }
        
        return ans;
    }
};