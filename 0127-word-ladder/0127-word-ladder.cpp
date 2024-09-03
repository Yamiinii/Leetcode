class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // If endWord is not in the wordList, return 0
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        queue<pair<string, int>> q; // Queue of pairs (word, level)
        q.push({beginWord, 1}); // Start with the beginWord and level 1

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            // Try all possible single letter transformations
            for (int i = 0; i < word.size(); ++i) {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue; // Skip if the letter is the same

                    word[i] = c;
                    if (word == endWord) {
                        return level + 1; // Return the length of the transformation sequence
                    }

                    if (wordSet.find(word) != wordSet.end()) {
                        q.push({word, level + 1});
                        wordSet.erase(word); // Remove the word from the set to avoid revisiting
                    }
                }
                word[i] = originalChar; // Restore the original character
            }
        }

        return 0; // If endWord is not reachable
    }
};