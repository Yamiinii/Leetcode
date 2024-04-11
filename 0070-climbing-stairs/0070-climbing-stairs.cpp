
class Solution {
public:
    std::vector<int> dp;
    
    int climbStairs(int n) {
        // Initialize dp vector with size n + 1 and default value 0
        dp.resize(n + 1, 0);
        
        // Base cases: 0 and 1 stairs
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 1;
        }
        
        // Start recursive calls
        return rec(n);
    }
    
    int rec(int n) {
        // Base case: if we reach the first step, return 1
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 1;
        }
        
        // Return memoized result if available
        if (dp[n] != 0) {
            return dp[n];
        }
        
        // Calculate the number of ways from current step
        dp[n] = rec(n - 1) + rec(n - 2);
        return dp[n];
    }
};