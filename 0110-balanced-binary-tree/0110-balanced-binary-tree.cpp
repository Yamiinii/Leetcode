class Solution {
public:
    int maxDepth(TreeNode* node) {
        if (node == nullptr)
            return 0;
        else {
            int lDepth = maxDepth(node->left);
            int rDepth = maxDepth(node->right);
            return 1 + max(lDepth, rDepth);  // Use the larger depth
        }
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;  // An empty tree is considered balanced
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (abs(leftDepth - rightDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }

        return false;
    }
};
