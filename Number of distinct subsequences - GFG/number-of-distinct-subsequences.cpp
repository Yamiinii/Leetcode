//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
const int MOD = 1000000007;
class Solution{
  public:	


int distinctSubsequences(string s) {
    int n = s.size();
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;  // Empty string is a subsequence

    unordered_map<char, int> lastOccurrence;

    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % MOD;
        char c = s[i - 1];
        if (lastOccurrence.find(c) != lastOccurrence.end()) {
            int j = lastOccurrence[c];
            dp[i] = (dp[i] - dp[j - 1] + MOD) % MOD;
        }
        lastOccurrence[c] = i;
    }

    return (int)dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends