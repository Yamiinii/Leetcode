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
      int res=INT_MIN;
    //Function to return maximum path sum from any node in a tree.
    int solve(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        
        int left = max(0, solve(root->left));//path ending at left
        int right = max(0, solve(root->right));//path ending at right
        //ending at root(current)
        int temp = max(root->val, max(left, right) + root->val);
        //path including current;passing through
        int ans=max(temp,left+right+root->val);
        
        res=max(res,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
         return res;
    }
};