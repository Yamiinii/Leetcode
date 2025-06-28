class Solution {
public:
    // string rec(int num,int n,string curr)
    // {
    //     if(n==num)
    //     return encode(curr);


    // }

    // string encode(string s)
    // {
    //     unordered_map<char,int> mpp;
    //     mpp[s[0]]=1;
    //     int j=0;
    //     for(int i=1;i<s.size();i++)
    //     {
    //         if(s[i]==s[i-1])
    //         mpp[j]++;
    //         else
    //         {
    //             j++;
    //             mpp[s[i]]++;
    //         }

    //     }
    //     string ans="";
    //     for(int i=0;i<mpp.size();i++)
    //     {
    //         ans+=to_string(mpp[s[i].second]);
    //         ans+=mpp[s[i]].first;
    //     }
    // }

    string encode(string s)
    {
        string ans="";
        int cnt=1;
        for(int i=1;i<=s.size();i++)
        {
            if(i<s.size() && s[i]==s[i-1])
            cnt++;
            else
            {
                ans+=to_string(cnt);
                ans+=s[i-1];
                cnt=1;
            }
        }

        return ans;
    }
    string countAndSay(int n) {
        if(n==1)
        return "1";
        string curr="1";
        for(int i=2;i<=n;i++)
        {
            curr=encode(curr);
        }
        return curr;
    }
};