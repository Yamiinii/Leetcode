class Solution {
public:
    int func(int i)
    {
        int ans=0;
        while(i)
        {
            if(i & 1)
            ans+=1;

            i=i>>1;
        }

        return ans;
    }

    vector<int> countBits(int n) {
        vector<int> v(n+1,0);
        for(int i=1;i<n+1;i++)
        {
            v[i]=func(i);
        }

        return v;
    }
};