class Solution {
public:
    int tribonacci(int n) {
        // Initialize a vector dp of size n+1 with initial values set to 0
        vector<int> dp(n + 1, 0);
        if (n == 0) return 0; // Handle the base case
        dp[1] = 1; // Set the second Tribonacci number to 1
        if (n == 1) return 1; // Handle the second base case
        dp[2] = 1; // Set the third Tribonacci number to 1
        for (int i = 3; i <= n; i++) {
            // Calculate the next Tribonacci number based on the sum of the previous three numbers
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        // Return the nth Tribonacci number
        return dp[n];
    }
};
