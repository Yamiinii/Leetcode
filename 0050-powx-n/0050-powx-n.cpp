class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        
        double ans = 1.0;
        long long nn = abs(static_cast<long long>(n)); // Handle INT_MIN case
        
        while (nn) {
            if (nn % 2 == 1) {
                ans *= x;
                nn--;
            } else {
                x *= x;
                nn /= 2;
            }
        }
        
        return (n < 0) ? 1.0 / ans : ans;
    }
};
