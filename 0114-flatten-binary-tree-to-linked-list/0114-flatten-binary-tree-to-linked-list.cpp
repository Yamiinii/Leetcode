class Solution {
public:
    TreeNode* rightmost (TreeNode* node) {
        // helper fn to find the rightmost node in left subtree.
        while (node->right) node = node->right;
        return node;
    }
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode* node = rightmost(root->left);
                node->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};