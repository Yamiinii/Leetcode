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
    int rec(TreeNode* root)
    {
        if(root==NULL)
        return 0;

        int ans=0;
        int left=rec(root->left);
        int right=rec(root->right);
        ans=1+max(left,right);

        return ans;
    }

    int maxDepth(TreeNode* root) {
        if(root==NULL)
        return 0;
        return rec(root);
    }
};