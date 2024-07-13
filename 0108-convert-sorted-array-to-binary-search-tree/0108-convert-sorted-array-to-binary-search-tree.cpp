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
    TreeNode* build(vector<int>& nums,int st ,int end)
    {
         if (st > end) {
            return NULL;
        }

        int mid = st + (end - st) / 2;
        TreeNode* root = new TreeNode(nums[mid]); // Use nums[mid] instead of mid
        root->left = build(nums, st, mid - 1); // Left subtree
        root->right = build(nums, mid + 1, end); // Right subtree

        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return  build(nums,0,nums.size()-1);
    }
};