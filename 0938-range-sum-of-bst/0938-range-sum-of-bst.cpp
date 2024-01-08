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
    void rec(TreeNode* root, int low, int high,int& sum)
    {
         if (!root) return; 
        if(root->val>=low && root->val<=high)
            sum+=root->val;
        
        if(root->left)
        {
            rec(root->left,low,high,sum);
        }
        if(root->right)
            rec(root->right,low,high,sum);
        
    
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        rec(root,low,high,sum);
        return sum;
    }
};