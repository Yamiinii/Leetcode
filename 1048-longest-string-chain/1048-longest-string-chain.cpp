#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        int maxChain = 1; // Initialize the maximum chain length to 1.

        // Sort the words by their length in ascending order.
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        for (const string& word : words) {
            // Initialize the chain length for the current word to 1.
            dp[word] = 1;

            // Generate all possible predecessors by removing one character.
            for (int i = 0; i < word.size(); i++) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);

                // Check if the predecessor exists in dp.
                if (dp.find(predecessor) != dp.end()) {
                    // Update the chain length for the current word.
                    dp[word] = max(dp[word], dp[predecessor] + 1);
                }
            }

            // Update the maximum chain length.
            maxChain = max(maxChain, dp[word]);
        }

        return maxChain;
    }
};