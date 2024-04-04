#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool rec(vector<vector<char>>& board, string word, int idx, int i, int j) {
        // Base case for recursion
        if (idx == word.length()) {
            return true; // Word found
        }

        // Boundary check
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
            return false; // Invalid position or mismatched character
        }

        // Mark current cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore neighbors
        bool found = rec(board, word, idx + 1, i - 1, j) ||
                     rec(board, word, idx + 1, i + 1, j) ||
                     rec(board, word, idx + 1, i, j - 1) ||
                     rec(board, word, idx + 1, i, j + 1);

        // Restore original state
        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (rec(board, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
