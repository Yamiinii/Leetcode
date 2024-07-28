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
    TreeNode* buildTree(vector<int> preorder,int prestart,int preend,vector<int> inorder,int instart,int inend,  unordered_map<int,int>& mpp)
    {
            if(instart>inend || prestart>preend)
            return NULL;
            
            TreeNode* root=new TreeNode(preorder[prestart]);
            int inRoot=mpp[root->val];
            int left=inRoot-instart;
            root->left=buildTree(preorder,prestart+1,prestart+left,inorder,instart,inRoot-1,mpp);
            root->right=buildTree(preorder,prestart+1+left,preend,inorder,inRoot+1,inend,mpp);
            return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        int n=preorder.size();
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            mpp[inorder[i]]=i;
        }
        return buildTree(preorder,0,n-1,inorder,0,n-1,mpp);
    }
};