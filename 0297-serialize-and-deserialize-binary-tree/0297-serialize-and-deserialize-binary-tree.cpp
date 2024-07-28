#include <string>
#include <sstream>
#include <queue>
#include <utility>

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
    // Serialize the binary tree to a string
    string serialize(TreeNode* root) {
        if (!root) {
            return "";
        }

        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();
            if (curNode == nullptr) {
                ss << "#,";
            } else {
                ss << curNode->val << ",";
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return ss.str();
    }

    // Deserialize the string to a binary tree
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        if (str == "#") {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            getline(ss, str, ',');
            if (str != "#") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            
            getline(ss, str, ',');
            if (str != "#") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
