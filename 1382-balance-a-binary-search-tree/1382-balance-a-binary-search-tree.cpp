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
    TreeNode* constructBalancedBST(vector<int>& v,int start,int end)
    {
      if(start>end)
          return NULL;
        
        int mid=start + (end - start) / 2;
        TreeNode* root=new TreeNode(v[mid]);
        
        root->left=constructBalancedBST(v,start,mid-1);
        root->right=constructBalancedBST(v,mid+1,end);
        return root;
    }
    
    void inorder(TreeNode* root,vector<int>& v)
    {
        if(!root)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return constructBalancedBST(v,0,v.size()-1);
    }
};