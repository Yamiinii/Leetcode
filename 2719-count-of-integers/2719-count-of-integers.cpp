class Solution {
private:
    const int MOD = 1000000007;
    int dp[30][401][2];

    int getDigitSum(string str) {
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            sum += (str[i] - '0');
        }
        return sum;
    }

    int solve(string &num, int min_sum, int max_sum, int tight, int currSum, int index) {
        if (index == num.length()) {
            return (currSum <= max_sum && currSum >= min_sum) ? 1 : 0;
        }

        if (dp[index][currSum][tight] != -1)
            return dp[index][currSum][tight];

        int ans = 0;
        int end = (tight == 1) ? (num[index] - '0') : 9;
        for (int curr = 0; curr <= end; curr++) {
            int newTight = (tight == 1 && curr == end) ? 1 : 0;
            ans = (ans + solve(num, min_sum, max_sum, newTight, currSum + curr, index + 1)) % MOD;
        }

        return dp[index][currSum][tight] = ans;
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int n1 = num1.length();
        int n2 = num2.length();

        memset(dp, -1, sizeof(dp));

        int ans = solve(num2, min_sum, max_sum, 1, 0, 0);

        memset(dp, -1, sizeof(dp));

        ans -= solve(num1, min_sum, max_sum, 1, 0, 0);
        int digitSum = getDigitSum(num1);
        if (digitSum <= max_sum && digitSum >= min_sum)
            ans++;

        ans %= MOD;

        return (ans + MOD) % MOD;
    }
};
