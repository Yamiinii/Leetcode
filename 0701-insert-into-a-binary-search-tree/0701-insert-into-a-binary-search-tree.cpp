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
    void addnode(TreeNode* newroot, int val)
    {
         if(val<newroot->val && newroot->left==NULL)
        {
          newroot->left=new TreeNode(val);
          return;
        }
        else if(val>newroot->val && newroot->right==NULL)
        {
          newroot->right=new TreeNode(val);
          return;
        }
        else
        {
          if(val<newroot->val)
          addnode(newroot->left,val);
          else
          addnode(newroot->right,val);
        }

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      if(root==NULL)
      return new TreeNode(val);
        TreeNode* newroot=root;
        addnode(newroot,val);
        return root;
     
    }
};