class Solution {
public:
    pair<int,int> dfs(TreeNode* root, int& count) {
        if (!root) return {0, 0};
        auto [lsum, lcnt] = dfs(root->left, count);
        auto [rsum, rcnt] = dfs(root->right, count);
        int sum = lsum + rsum + root->val;
        int cnt = lcnt + rcnt + 1;
        if (sum / cnt == root->val) ++count; // integer division
        return {sum, cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
};
