class Solution {
public:
    bool isPowerOfTwo(int n) {
           int cnt = 0;
    while (n > 0) {
        if ((n & 1) == 1) {
            cnt++;
        }
        n = n >> 1; // keep dividing n by 2 using right
                    // shift operator
    }
 
    if (cnt == 1) { // if cnt = 1 only then it is power of 2
        return true;
    }
    return false;
    }
};