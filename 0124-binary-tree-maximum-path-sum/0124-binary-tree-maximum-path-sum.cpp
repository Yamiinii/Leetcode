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
    int rec(TreeNode* root,int& ans)
    {
        if(root==NULL)
        return 0;

        int left=max(0,rec(root->left,ans));
        int right=max(0,rec(root->right,ans));

        // int ans=0;
        //it should be global
        // if(left+right+root->val>left)
        // ans=left+right+root->val;
        // else if(left>right)
        // ans=left;
        //but I am thinking what if it is not the fault of root but either of right or left
        // else
        // ans=right;
        ans=max(ans,root->val+left+right);
        return root->val + max(left, right);  
    }

    int maxPathSum(TreeNode* root) {
        if(root==NULL)
        return 0;
        if(root->left ==NULL && root->right ==NULL)
        return root->val;
        //for negative valued trees
        //return rec(root,0);
        int ans=INT_MIN;
        rec(root,ans);
        return ans;
    }
};