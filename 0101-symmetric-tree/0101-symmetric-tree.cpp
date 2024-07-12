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

 //********************************this is not optimal...see first one only***************
class Solution {
public:
    bool isSym(TreeNode* Left,TreeNode* Right)
    {
        if(Left==NULL || Right==NULL)
            return Left==Right;
        if(Left->val!=Right->val)
            return false;
        
        return isSym(Left->left,Right->right) && isSym(Left->right , Right->left);
    }
    
    bool isSymmetric(TreeNode* root) { 
        if (root == nullptr)
            return true;
        
        return isSym(root->left,root->right);
    }
};
