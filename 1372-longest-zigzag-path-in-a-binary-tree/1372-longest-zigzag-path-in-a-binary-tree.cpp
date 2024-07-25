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
    int longestZigZag(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int longest = 0;
        
        // DFS to find the longest zigzag path
        dfs(root->left, true, 1, longest);  // Start with left child
        dfs(root->right, false, 1, longest);  // Start with right child
        
        return longest;
    }
    
    void dfs(TreeNode* node, bool isLeft, int currentLength, int &longest) {
        if (node == nullptr) {
            return;
        }
        
        // Update the longest zigzag path found so far
        longest = max(longest, currentLength);
        
        // Recursively explore left and right subtrees
        if (isLeft) {
            dfs(node->left, true, 1, longest);  // Reset length for left child
            dfs(node->right, false, currentLength + 1, longest);  // Continue with right child
        } else {
            dfs(node->right, false, 1, longest);  // Reset length for right child
            dfs(node->left, true, currentLength + 1, longest);  // Continue with left child
        }
    }
};
