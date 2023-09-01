class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0); // Initialize a vector of size num+1 with 0s
        for (int n = 1; n <= num; n++) {
            ans[n] = ans[n >> 1] + (n & 1); // Use bit manipulation to count set bits
        }
        return ans;
    }
};
