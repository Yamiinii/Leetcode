class Solution {
public:
    const int MOD = 1e9+7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> last(256,-1);
        vector<long long> dp(n+1);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            dp[i] = (2*dp[i-1])%MOD;
            if(last[s[i-1]] != -1){
                dp[i] = (dp[i] - dp[last[s[i-1]]])%MOD;
            }
            last[s[i-1]] = (i-1);
        }
        return (dp[n]-1)%MOD>0?(dp[n]-1)%MOD:(dp[n]-1)%MOD+MOD;
    }
};