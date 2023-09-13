/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr; // Base case: If the current node is null, return null.
        }
        
        if (root == p || root == q) {
            return root; // If either p or q is the current node, it's the common ancestor.
        }
        
        // Recursively search in the left and right subtrees.
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left && right) {
            return root; // If both left and right subtrees have found a common ancestor, root is the LCA.
        } else if (left) {
            return left; // If only left subtree has a common ancestor, return it.
        } else {
            return right; // If only right subtree has a common ancestor, return it.
        }
    }
};
