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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }

private:
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if (!root) {
            return true; // An empty tree is a valid BST.
        }

        if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) {
            return false; // If the current node's value violates the BST property, return false.
        }

        // Recursively check the left and right subtrees with updated min and max values.
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};
