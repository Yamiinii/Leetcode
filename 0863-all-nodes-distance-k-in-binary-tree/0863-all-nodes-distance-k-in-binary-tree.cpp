#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// Definition for a binary tree node.

class Solution {
public:
    void parentMap(TreeNode* root, unordered_map<int, TreeNode*>& parent) {
        if (!root) return;
        
        queue<TreeNode*> q;
        q.push(root);
        parent[root->val] = NULL; // Root has no parent

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left->val] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right->val] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parent;
        parentMap(root, parent);
        
        unordered_set<int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target->val);
        
        int curr = 0;
        while (!q.empty()) {
            if (curr == k) break;
            
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Check left child
                if (node->left && !visited.count(node->left->val)) {
                    q.push(node->left);
                    visited.insert(node->left->val);
                }

                // Check right child
                if (node->right && !visited.count(node->right->val)) {
                    q.push(node->right);
                    visited.insert(node->right->val);
                }

                // Check parent
                if (parent[node->val] && !visited.count(parent[node->val]->val)) {
                    q.push(parent[node->val]);
                    visited.insert(parent[node->val]->val);
                }
            }
            
            ++curr;
        }
        
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};
