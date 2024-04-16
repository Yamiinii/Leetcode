#include <queue>

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        std::queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;

        while (!q.empty()) {
            int size = q.size();
            if (currentDepth == depth - 1) {
                while (size--) {
                    TreeNode* node = q.front();
                    q.pop();

                    // Add new nodes at the current level
                    TreeNode* leftSubtree = node->left;
                    node->left = new TreeNode(val);
                    node->left->left = leftSubtree;

                    TreeNode* rightSubtree = node->right;
                    node->right = new TreeNode(val);
                    node->right->right = rightSubtree;
                }
                break; // No need to continue BFS since we've added the new row
            }

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            currentDepth++;
        }

        return root;
    }
};
