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
    TreeNode* build(vector<int>& preorder,int prestart,int preend, vector<int>& inorder,int instart,int inend,unordered_map<int,int>& mpp)
    {
        if(instart>inend || prestart>preend)
        return NULL;

        int inroot=mpp[preorder[prestart]];
        int left=inroot-instart;

        TreeNode* root=new TreeNode(preorder[prestart]);
        root->left=build(preorder,prestart+1,prestart+left,inorder,instart,inroot-1,mpp);
        root->right=build(preorder,prestart+1+left,preend,inorder,inroot+1,inend,mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        return build(preorder,0,n-1,inorder,0,n-1,mpp);
    }
};