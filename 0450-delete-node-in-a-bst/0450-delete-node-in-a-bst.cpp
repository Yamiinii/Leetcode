class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root; // Return null if root is null

        // If key to be deleted is less than the root node, then it lies in left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // If key to be deleted is greater than the root node, then it lies in right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // If key is same as root's key, then this is the node to be deleted
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: get the inorder successor (smallest in the right subtree)
            TreeNode* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->val = temp->val;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }

private:
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        /* loop down to find the leftmost leaf */
        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }
};
