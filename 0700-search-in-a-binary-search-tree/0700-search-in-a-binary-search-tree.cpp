/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) {
            return nullptr; // Value not found, return nullptr.
        }

        if (val == root->val) {
            return root; // Value found, return the current node.
        } else if (val < root->val) {
            return searchBST(root->left, val); // Recursively search in the left subtree.
        } else {
            return searchBST(root->right, val); // Recursively search in the right subtree.
        }
    }
};
