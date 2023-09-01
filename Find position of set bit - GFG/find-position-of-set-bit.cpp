//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int isPowerOfTwo(unsigned n)
{
    return n && (!(n & (n - 1)));
}

    int findPosition(int n) {
        // code hereif (!isPowerOfTwo(n))
        if (!isPowerOfTwo(n))
        return -1;
 
    unsigned i = 1, pos = 1;
 
    // Iterate through bits of n till we find a set bit
    // i&n will be non-zero only when 'i' and 'n' have a set bit
    // at the same position
    while (!(i & n)) {
        // Unset the current bit and set the next bit in 'i'
        i = i << 1;
 
        // Increment the position
        ++pos;
    }
 
    return pos;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends