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
    int rec(TreeNode* root,int &maxi)
    {
        if(root==NULL)
        return 0;
        int ans=0;

        int left=rec(root->left,maxi);
        int right=rec(root->right,maxi);

        int curr=1+max(left,right);
        maxi=max(maxi,curr);
        return curr;
        
    }

    int maxDepth(TreeNode* root) {
        int maxi=0;
        rec(root,maxi);
        return maxi;
    }
};