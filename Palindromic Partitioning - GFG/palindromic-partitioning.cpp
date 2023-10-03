//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// class Solution{
// public:
// bool iisPallindrome(string X, int i, int j) {
// 	while (i <= j) {
// 		if (X[i] != X[j])
// 			return false;
// 		i++, j--;
// 	}

// 	return true;
// }
//  int solve(string str, int i, int j, vector<vector<int>>& dp) {
//         if (i >= j)
//             {dp[i][j]=0;
//                 return 0;}
            
    

//          if (iisPallindrome(str,i,j)==true)
//         {
//             dp[i][j]=0;
//             return 0;
//         }
        
//         if (dp[i][j] != -1)
//             return dp[i][j];

//         int mn = INT_MAX;
//         for (int k = i; k < j; k++) {
//             // int temp_ans = 1+solve(str, i, k, dp) + solve(str, k + 1, j, dp);

//             //     mn =min(mn,temp_ans);
//             int left, right;
// 		if (dp[i][k] == -1)
// 			left = solve(str, i, k,dp);
// 		else
// 			left = dp[i][k];

// 		if (dp[k + 1][j] == -1)
// 			right = solve(str, k + 1, j,dp);
// 		else
// 			right = dp[k + 1][j];

// 		int temp_ans = left + right + 1;
// 		mn = min(mn, temp_ans);
//         }
//         return dp[i][j] = mn;
//     }
//     int palindromicPartition(string str)
//     {
//         // code here
//         int N=str.size();
//          vector<vector<int>> dp(N, vector<int>(N, -1));
        
//         // Call the recursive function to solve the problem
//         return solve(str, 0, str.size()-1, dp);
//     }
// };

class Solution {
public:
    int palindromicPartition(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 1 || isPalindrome[j + 1][i - 1])) {
                    isPalindrome[j][i] = true;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                for (int j = 0; j < i; j++) {
                    if (isPalindrome[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n - 1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends