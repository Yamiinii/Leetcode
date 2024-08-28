class Trie {
public:
    Trie* links[26] = {nullptr}; // Initialize the links array with nullptr
    bool isword = false;
};

class Solution {
public:
    void addWord(Trie* curr, const string& word) {
        for (char ch : word) {
            if (!curr->links[ch - 'a']) {
                curr->links[ch - 'a'] = new Trie();
            }
            curr = curr->links[ch - 'a'];
        }
        curr->isword = true;
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& temp, Trie* trie, vector<string>& ans, int i, int j) {
        if (!trie) return;

        if (trie->isword) {
            ans.push_back(temp);
            trie->isword = false; // To avoid adding the same word multiple times
        }
        
        visited[i][j] = true;
        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};
        
        for (int k = 0; k < 4; ++k) {
            int xi = i + x[k];
            int yi = j + y[k];
            if (xi >= 0 && xi < board.size() && yi >= 0 && yi < board[0].size() && !visited[xi][yi] && trie->links[board[xi][yi] - 'a']) {
                temp.push_back(board[xi][yi]);
                dfs(board, visited, temp, trie->links[board[xi][yi] - 'a'], ans, xi, yi);
                temp.pop_back(); // Remove the last character after returning from DFS
            }
        }
        visited[i][j] = false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for (const auto& word : words) {
            addWord(root, word);
        }
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char ch = board[i][j];
                if (root->links[ch - 'a']) {
                    string temp(1, ch);
                    dfs(board, visited, temp, root->links[ch - 'a'], ans, i, j);
                }
            }
        }
        return ans;
    }
};
