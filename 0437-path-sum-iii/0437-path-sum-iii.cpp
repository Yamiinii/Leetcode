#include <unordered_map>

class Solution {
public:
    // Helper function to perform DFS and count paths with the given sum
    void dfs(TreeNode* root, int target, std::unordered_map<long long, int>& mpp, long long currentSum, int& cnt) {
        if (!root) return;

        // Update the current path sum
        currentSum += root->val;

        // Check if the current path sum equals the target
        if (currentSum == target) {
            cnt++;
        }

        // Check if there is a prefix sum that gives the required sum
        if (mpp.find(currentSum - target) != mpp.end()) {
            cnt += mpp[currentSum - target];
        }

        // Update the prefix sum map with the current path sum
        mpp[currentSum]++;

        // Recurse to left and right subtrees
        dfs(root->left, target, mpp, currentSum, cnt);
        dfs(root->right, target, mpp, currentSum, cnt);

        // Backtrack: remove the current path sum from the map
        mpp[currentSum]--;
    }
    
    // Main function to count the number of paths with sum equal to targetSum
    int pathSum(TreeNode* root, int targetSum) {
        std::unordered_map<long long, int> mpp;
        int cnt = 0;
        dfs(root, targetSum, mpp, 0, cnt);
        return cnt;
    }
};
