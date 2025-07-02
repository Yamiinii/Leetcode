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
    // int heigh(TreeNode* root)
    // {
    //     if(root==NULL)
    //     return 0;

    //     int lheight=heigh(root->left);
    //     int rheight=heigh(root->right);

    //     return 1+max(lheight,rheight);

    // }

    // bool rec(TreeNode* root)
    // {
    //     if(root==NULL)
    //     return 0;

    //     bool left=rec(root->left);
    //     bool right=rec(root->right);

    //     int lheight=heigh(root->left);
    //     int rheight=heigh(root->right);

    //     return left && right && |lheight-rheight|<=1;
    // }

        pair<bool, int> rec(TreeNode* root) {
        if (root == nullptr)
            return {true, 0};

        pair<bool, int> left = rec(root->left);
        pair<bool, int> right = rec(root->right);

        bool balanced = left.first && right.first && abs(left.second - right.second) <= 1;
        int height = 1 + max(left.second, right.second);

        return {balanced, height};
    }

    bool isBalanced(TreeNode* root) {
        return rec(root).first;
    }
};