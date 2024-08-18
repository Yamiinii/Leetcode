class Solution {
public:
    // Helper function to perform in-order traversal
    bool inorder(TreeNode* root, int k, int &cnt, int &result) {
        if (root == nullptr) {
            return false;
        }

        // Traverse the left subtree
        if (inorder(root->left, k, cnt, result)) {
            return true; // If we found the k-th smallest, no need to continue
        }

        // Visit the current node
        cnt++;
        if (cnt == k) {
            result = root->val;
            return true; // Found the k-th smallest element
        }

        // Traverse the right subtree
        return inorder(root->right, k, cnt, result);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;    // To keep track of the count of visited nodes
        int result = 0; // To store the k-th smallest value
        inorder(root, k, cnt, result);
        return result;  // Return the k-th smallest value
    }
};
