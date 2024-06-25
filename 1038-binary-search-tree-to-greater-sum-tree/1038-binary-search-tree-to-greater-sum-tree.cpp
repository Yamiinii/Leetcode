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
    int sum=0;
    void recursion(TreeNode* root)
    {
        if (root == nullptr) return;

        // Traverse right subtree
        recursion(root->right);

        // Update sum with current node's value
        sum += root->val;

        // Update current node's value
        root->val = sum;

        // Traverse left subtree
        recursion(root->left);
        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        recursion(root);
        return root;
    }
};