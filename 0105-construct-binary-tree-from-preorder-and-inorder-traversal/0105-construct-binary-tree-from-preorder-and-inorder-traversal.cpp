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
    TreeNode* buildTree(vector<int>& preorder,int prestart,int preend, vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int> &mpp)
    {
        if(inStart>inEnd || prestart>preend)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inRoot=mpp[root->val];
        int numsleft=inRoot-inStart;
        root->left=buildTree(preorder,prestart+1,prestart+numsleft,inorder,inStart,inRoot-1,mpp);
        root->right=buildTree(preorder,prestart+numsleft+1,preend,inorder,inRoot+1,inEnd,mpp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map <int,int> inMap;
        for(int i=0;i<inorder.size();i++)
        {
            inMap[inorder[i]]=i;
        }
        int n=preorder.size();
        
        return buildTree(preorder,0,n-1,inorder,0,n-1,inMap);
    }
};