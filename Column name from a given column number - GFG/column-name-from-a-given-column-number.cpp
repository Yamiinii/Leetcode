//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    string colName(long long int n) {
        string s;
        while (n > 0) {
            // Calculate the remainder when divided by 26
            int remainder = (n - 1) % 26;

            // Append the corresponding character to the result string
            s = char('A' + remainder) + s;

            // Update n to the next quotient
            n = (n - 1) / 26;
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends