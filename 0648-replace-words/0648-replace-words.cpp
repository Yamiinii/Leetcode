class Node {
public:
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    string getRootWord(string word) {
        Node* node = root;
        string prefix = "";
        for (char ch : word) {
            if (node->isEnd()) {
                return prefix;
            }
            if (!node->containsKey(ch)) {
                return word;
            }
            node = node->get(ch);
            prefix += ch;
        }
        return node->isEnd() ? prefix : word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (string root : dictionary) {
            trie.insert(root);
        }

        stringstream ss(sentence);
        string word;
        string result = "";

        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += trie.getRootWord(word);
        }

        return result;
    }
};
