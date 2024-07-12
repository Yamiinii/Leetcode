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
    TreeNode* build(vector<int>& postorder,int poststart,int postend, vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int> &mpp)
    {
        if(inStart>inEnd || poststart>postend)
            return NULL;
        
        TreeNode* root=new TreeNode(postorder[postend]);
        int inRoot=mpp[root->val];
        int numsleft=inRoot-inStart;
        root->left=build(postorder,poststart,poststart+numsleft-1,inorder,inStart,inRoot-1,mpp);
        root->right=build(postorder,poststart+numsleft,postend-1,inorder,inRoot+1,inEnd,mpp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        unordered_map<int,int> inMap;
        for(int i=0;i<n;i++)
        {
            inMap[inorder[i]]=i;
        }
        
        return build(postorder,0,n-1,inorder,0,n-1,inMap);
    }
};