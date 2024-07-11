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
    // **********888888888888883uqrwidoasxz------  
    //     we are using only left height and only right height by not adding one
    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l = height(root->left);
        int r = height(root->right);
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        int heigh = height(root->left) + height(root->right);
        int ans = max(heigh, max(l, r));
        return ans;
    }
};
