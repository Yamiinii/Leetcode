class Solution {
public:
    int minInsertions(string X) {
         string Y = X; // Create a copy of X
        reverse(Y.begin(), Y.end()); // Reverse Y
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
        return m-v[m][n];
    }
};