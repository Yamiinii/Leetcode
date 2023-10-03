//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int countWays(int N, string X) {
        int mod = 1003; // Define a modulo value for calculations
        int n = X.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        // Initialize the dp table for single characters
        for (int i = 0; i < n; i++) {
            if (X[i] == 'T') {
                dp[i][i][0] = 0;
                dp[i][i][1] = 1;
            } else {
                dp[i][i][0] = 1;
                dp[i][i][1] = 0;
            }
        }

        // Fill in the dp table for different lengths of subexpressions
        for (int len = 3; len <= n; len += 2) {
            for (int i = 0; i < n - len + 1; i += 2) {
                int j = i + len - 1;
                dp[i][j][0] = dp[i][j][1] = 0;

                for (int k = i + 1; k < j; k += 2) {
                    char op = X[k];
                    int leftTrue = dp[i][k - 1][1];
                    int leftFalse = dp[i][k - 1][0];
                    int rightTrue = dp[k + 1][j][1];
                    int rightFalse = dp[k + 1][j][0];

                    if (op == '|') {
                        dp[i][j][1] = (dp[i][j][1] + leftTrue * rightFalse + leftFalse * rightTrue + leftTrue * rightTrue) % mod;
                        dp[i][j][0] = (dp[i][j][0] + leftFalse * rightFalse) % mod;
                    } else if (op == '&') {
                        dp[i][j][1] = (dp[i][j][1] + leftTrue * rightTrue) % mod;
                        dp[i][j][0] = (dp[i][j][0] + leftTrue * rightFalse + leftFalse * rightTrue + leftFalse * rightFalse) % mod;
                    } else if (op == '^') {
                        dp[i][j][1] = (dp[i][j][1] + leftTrue * rightFalse + leftFalse * rightTrue) % mod;
                        dp[i][j][0] = (dp[i][j][0] + leftTrue * rightTrue + leftFalse * rightFalse) % mod;
                    }
                }
            }
        }

        return dp[0][n - 1][1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends