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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if (!root) return {}; // Handle empty tree case
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool forward = true;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> v(n);//initialisation is must
            for(int i=0;i<n;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                int index = forward ? i : n - 1 - i; // Determine index based on direction
                v[index] = front->val;
                
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            
            ans.push_back(v);
            forward=!forward;
        }
        return ans;
    }
};