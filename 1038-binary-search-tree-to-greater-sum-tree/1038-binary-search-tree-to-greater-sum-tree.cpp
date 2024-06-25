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
        recursion(root->right);
        sum += root->val;
        root->val = sum;
        recursion(root->left);
        
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        recursion(root);
        return root;
    }
};