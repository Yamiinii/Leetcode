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
    void dfs(TreeNode* root, int maxVal, int &res) {
        if (root == nullptr) {
            return;
        }
        
        if (root->val >= maxVal) {
            res++;
        }
        
        dfs(root->left, max(maxVal, root->val), res);
        dfs(root->right, max(maxVal, root->val), res);
    }
    
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int res = 0;
        dfs(root, root->val, res);
        return res;
    }
};
