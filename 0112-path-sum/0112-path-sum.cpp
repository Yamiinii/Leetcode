class Solution {
public:
    bool check(TreeNode* root, int targetSum) {
 if(!root){
            return false;
        }
        // if u are on leaf node
        if(!root->left && !root->right && targetSum -root->val==0){
            return true;
        }

        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        
        return check(root, targetSum);
    }
};
