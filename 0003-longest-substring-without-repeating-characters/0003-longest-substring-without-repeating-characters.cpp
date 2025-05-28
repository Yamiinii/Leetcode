class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==1)
        return 1;
        if(n==0)
        return 0;
        int front=0;
        int back=0;
        int maxi=1;
        unordered_map<char,int> mpp;
        mpp[s[0]]++;
        //didn't check for back out of bounds here
        //back<n is wrong but not back<n-1
        //This means that on the final iteration where back == n - 1, you do back++, making back == n, and then access s[back], which is out-of-bounds.
        while(front<=back && back<n-1)
        {
            back++;
            // I forgot to increment in the map
            mpp[s[back]]++;
            //did mpp[back] here by mistake also i wrote mpp[s[back]] > 0
            if (mpp[s[back]] > 1)
            {
                // while(s[front]!=s[back])
                while (mpp[s[back]] > 1)
                {
                    mpp[s[front]]--;
                    front++;
                }
                // front++;
                // maxi=max(maxi,back-front+1);
            }
            //mpp[s[back]]++;
            maxi=max(maxi,back-front+1);
        }

        return maxi;
    }
};