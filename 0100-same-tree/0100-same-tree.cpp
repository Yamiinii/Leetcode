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
    bool rec(TreeNode* p, TreeNode* q)
    {
        if(p==NULL && q==NULL)
        return true;

        if(p==NULL || q==NULL)
        return false;

        bool left=rec(p->left,q->left);
        bool right=rec(p->right,q->right);

        if(p->val == q->val && left && right)
        return true;

        return false;

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return rec(p,q);
    }
};