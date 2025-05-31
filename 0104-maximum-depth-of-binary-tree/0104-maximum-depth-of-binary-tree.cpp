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

        int left=root->left?rec(root->left):0;
        int right=root->right?rec(root->right):0;

        ans=1+max(left,right);

        return ans;
        
    }

    int maxDepth(TreeNode* root) {
        return rec(root);
    }
};