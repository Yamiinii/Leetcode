class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        int prefixXOR = 0;
        vector<int> freq(1024, 0);
        freq[0] = 1; // Initial prefix XOR is 0
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            prefixXOR ^= 1 << (word[i] - 'a'); // Calculate XOR value
            cnt += freq[prefixXOR]; // Add count of previous prefix XORs with the same value
            for (int j = 0; j < 10; j++) {
                cnt += freq[prefixXOR ^ (1 << j)]; // Check other possibilities of wonderful substrings
            }
            freq[prefixXOR]++;
        }

        return cnt;
    }
};
