class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for (int n = 0; n <= num; n++) {
            bitset<32> binary(n); // Use std::bitset to represent the binary number
            ans.push_back(binary.count()); // Count the number of set bits (1s)
        }
        return ans;
    }
};
