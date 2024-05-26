class Solution {
public:
    int mod = 1e9+7;
    int solve(int n,int a,int l,vector<vector<vector<int>>>& v){
        if(a==2||l==3)return 0;
        if(n==0)return 1;
        if(v[n][a][l] != -1)return v[n][a][l];
        long long int ans = 0;
        ans = solve(n-1,a,0,v)%mod;
        ans = (ans+solve(n-1,a+1,0,v)%mod)%mod;
        ans = (ans+solve(n-1,a,l+1,v)%mod)%mod;
        return v[n][a][l] = ans;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> v(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(n,0,0,v);
    }
};