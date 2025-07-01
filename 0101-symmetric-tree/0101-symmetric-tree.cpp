class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;

        bool outer = check(left->left, right->right);
        bool inner = check(left->right, right->left);
        
        return outer && inner;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        return check(root->left, root->right);
    }
};
