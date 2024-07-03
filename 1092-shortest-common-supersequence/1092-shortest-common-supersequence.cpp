class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int m=X.size();
        int n=Y.size();
         vector<vector<int>> v(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(X[i-1]==Y[j-1])
                v[i][j]=1+v[i-1][j-1];
                else
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
       string s="";
while(m>0 && n>0)
{
    if(X[m-1]==Y[n-1])
    {
        s+=X[m-1];
        m--;
        n--;
    }
    else if(v[m-1][n]>=v[m][n-1])
    {
        s+=X[m-1];
        m--;
    }
    else
    {
        s+=Y[n-1];
        n--;
    }
}
while(m>0)
{
    s+=X[m-1];
    m--;
}
while(n>0)
{
    s+=Y[n-1];
    n--;
}

reverse(s.begin(),s.end());
return s;

        
    }
};