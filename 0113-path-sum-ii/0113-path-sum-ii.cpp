#include <vector>
using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // Helper function to perform DFS and find all paths with the given sum
    void dfs(TreeNode* root, int target, int currentSum, vector<vector<int>>& result, vector<int>& path) {
        if (!root) return;

        currentSum += root->val;
        path.push_back(root->val);

        // Check if the current path sum equals the target and if it's a leaf node
        if (currentSum == target && !root->left && !root->right) {
            result.push_back(path);
        }

        // Recurse to left and right subtrees with updated current sum
        if (root->left) dfs(root->left, target, currentSum, result, path);
        if (root->right) dfs(root->right, target, currentSum, result, path);

        // Backtrack: remove the last element before returning to the parent node
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, 0, result, path);
        return result;
    }
};
