class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int i = 0, ans = 0;
        int N=s.size();
        int maxFreq=0;
        map<int, int> freq;
for (int j=0; j < N; ++j) {
    freq[s[j]]++;
    maxFreq=max(maxFreq,freq[s[j]]);
    while(j-i+1-maxFreq>k)
    {
        freq[s[i++]]--;
    }
    ans = max(ans, j - i + 1); // the window [i, j] is the maximum window we've found thus far
}
return ans;
    }
};