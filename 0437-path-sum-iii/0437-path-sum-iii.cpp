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
private:
    void dfs(TreeNode* root, long long targetSum, int& count, unordered_map<long long, int>& mp, long long sum) {
        if (root == nullptr) {
            return;
        }
        
        sum += root->val;
        
        if (sum == targetSum) {
            count++;
        }
        
        if (mp.find(sum - targetSum) != mp.end()) {
            count += mp[sum - targetSum];
        }
        
        mp[sum]++;
        
        dfs(root->left, targetSum, count, mp, sum);
        dfs(root->right, targetSum, count, mp, sum);
        
        mp[sum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<long long, int> mp;
        dfs(root, targetSum, count, mp, 0);
        return count;
    }
};
