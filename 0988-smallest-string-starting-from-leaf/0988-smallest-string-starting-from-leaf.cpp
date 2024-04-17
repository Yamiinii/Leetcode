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
    void dfs(TreeNode* node, string path, string& smallestString) {
        // Base case: if the node is null, return
        if (!node) {
            return;
        }

        // Convert the current node's value to the corresponding character
        char currentChar = 'a' + node->val;
        
        // Prepend the current character to the path (to form a leaf-to-root path)
        path = currentChar + path;

        // Check if the node is a leaf node (both children are null)
        if (!node->left && !node->right) {
            // Compare the current path with the smallest string found so far
            if (smallestString.empty() || path < smallestString) {
                smallestString = path;
            }
        }

        // Recur for the left and right children
        dfs(node->left, path, smallestString);
        dfs(node->right, path, smallestString);
    }

    // Main function to find the smallest string from leaf to root
    string smallestFromLeaf(TreeNode* root) {
        // Define a string to hold the smallest string from leaf to root
        string smallestString;
        
        // Perform DFS from the root node
        dfs(root, "", smallestString);
        
        // Return the smallest string found
        return smallestString;
    }
};