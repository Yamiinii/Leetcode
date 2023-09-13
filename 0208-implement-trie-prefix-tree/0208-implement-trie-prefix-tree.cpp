#include <iostream>
using namespace std;

struct node {
    node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, node* newNode) {
        links[ch - 'a'] = newNode;
    }

    node* get(char ch) {
        return links[ch - 'a'];
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
    node* root;

public:
    Trie() {
        root = new node();
    }

    void insert(string word) {
        node* currentNode = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (!currentNode->containsKey(ch)) {
                currentNode->put(ch, new node());
            }
            currentNode = currentNode->get(ch);
        }
        currentNode->setEnd();
    }

    bool search(string word) {
        node* currentNode = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (!currentNode->containsKey(ch)) {
                return false;
            }
            currentNode = currentNode->get(ch);
        }
        return currentNode->isEnd();
    }

    bool startsWith(string prefix) {
        node* currentNode = root;
        for (int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if (!currentNode->containsKey(ch)) {
                return false;
            }
            currentNode = currentNode->get(ch);
        }
        return true;
    }
};


