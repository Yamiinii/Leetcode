#include <cmath>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        int sqrt_num = static_cast<int>(sqrt(num));
        return sqrt_num * sqrt_num == num;
    }

    bool judgeSquareSum(int c) {
        for (int a = 0; a <= sqrt(c); ++a) {
            int b_squared = c - a * a;
            if (isPerfectSquare(b_squared)) {
                return true;
            }
        }
        return false;
    }
};
