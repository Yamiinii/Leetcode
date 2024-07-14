#include <string>
#include <queue>
#include <sstream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null,";
        }

        string s = to_string(root->val) + ","; // Append the root value
        s += serialize(root->left);  // Serialize the left subtree
        s += serialize(root->right); // Serialize the right subtree
        return s; // Return the complete serialized string
    }

    TreeNode* deserialize_helper(queue<string> &q) {
        string s = q.front();
        q.pop();
        if (s == "null") return nullptr; // Use "null" for consistency with serialize
        TreeNode* root = new TreeNode(stoi(s));
        root->left = deserialize_helper(q);
        root->right = deserialize_helper(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string s;

        while (getline(ss, s, ',')) { // Split by comma
            q.push(s);
        }

        return deserialize_helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
