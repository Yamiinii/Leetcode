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
    bool find(TreeNode* root, int k, unordered_map<int,int> &mpp) 
    {
        if (!root) {
            return false; // Base case: If the node is null, return false.
        }
          if(mpp.find(k-root->val)!=mpp.end())
            return true;

            mpp[root->val]++;

//         if(root->left)
//             find(root->left,k,mpp);
//         if(root->right)
//             find(root->right,k,mpp);
        
//         return false;
           return find(root->left, k, mpp) || find(root->right, k, mpp);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        unordered_map<int,int> mpp;
        return find(root,k,mpp);
    }
};