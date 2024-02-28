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
    void rec(TreeNode* root,int &leftval,int& maxdepth,int depth)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            if (depth > maxdepth) {
                maxdepth = depth;
                leftval = root->val;
            }
            return;
        }
        rec(root->left,leftval,maxdepth,depth+1);
        rec(root->right,leftval,maxdepth,depth+1);
        
        
    }
    
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return -1;
        int left=root->val;
        int maxdepth=0;
        rec(root,left,maxdepth,0);
        return left;
        
        
    }
};