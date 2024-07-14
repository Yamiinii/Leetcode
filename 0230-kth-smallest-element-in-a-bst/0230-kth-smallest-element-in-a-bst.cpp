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
    // Inorder traversal to find the k-th smallest element
    int inorder(TreeNode* root, int k, int &cnt) {
        if (root == NULL) {
            return -1; // Return a sentinel value for not found
        }
        
        // Traverse the left subtree
        int left = inorder(root->left, k, cnt);
        if (left != -1) return left; // If found in left subtree, return it
        
        // Increment count
        cnt++;
        
        // Check if current node is the k-th smallest
        if (cnt == k) {
            return root->val; // Return the value of the k-th smallest node
        }
        
        // Traverse the right subtree
        return inorder(root->right, k, cnt);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return inorder(root, k, cnt);
    }
};
