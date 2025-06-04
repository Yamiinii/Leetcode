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
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL|| root==p || root==q)
        return root;

        TreeNode* left=rec(root->left,p,q);
        TreeNode* right=rec(root->right,p,q);

        if(left && right)
        return root;

        return left?left:right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)
        return root;

        return rec(root,p,q);
    }
};