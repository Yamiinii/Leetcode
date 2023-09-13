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
    int kthSmallest(TreeNode* root, int k) {
        int count = countNodes(root->left) + 1; // Count of nodes in the left subtree + 1 (current node)
        
        if (k == count) {
            return root->val; // The kth smallest element is the current node's value
        } else if (k < count) {
            return kthSmallest(root->left, k); // The kth smallest element is in the left subtree
        } else {
            return kthSmallest(root->right, k - count); // The kth smallest element is in the right subtree
        }
    }
    
    int countNodes(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
};
