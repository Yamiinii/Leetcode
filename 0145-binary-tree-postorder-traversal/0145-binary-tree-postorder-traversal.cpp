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
    void reverse(TreeNode* start, TreeNode* end) {
        if (start == end)
            return;
        TreeNode* prev = start;
        TreeNode* curr = start->right;
        TreeNode* next;
        while (prev != end) {
            next = curr->right;
            curr->right = prev;
            prev = curr;
            curr = next;
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> out;
        if (root == nullptr)
            return out;

        TreeNode* dummy = new TreeNode(-1);
        dummy->left = root;
        root = dummy;
        TreeNode* pre = nullptr;

        while (root) {
            if (root->left) {
                pre = root->left;
                while (pre->right && pre->right != root)
                    pre = pre->right;

                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    TreeNode* node = pre;
                    reverse(root->left, pre);
                    while (node != root->left) {
                        out.push_back(node->val);
                        node = node->right;
                    }
                    out.push_back(node->val); // Print again since we are stopping at node = root->left
                    reverse(pre, root->left);
                    pre->right = nullptr;
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }

        delete dummy;
        return out;
    }
};