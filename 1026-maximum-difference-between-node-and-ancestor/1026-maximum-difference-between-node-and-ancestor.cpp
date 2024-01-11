class Solution {
    public: int diff=0;
public:

/////////void differ(TreeNode* root, int &minVal, int &maxVal,int & diff) not working why??????
    void differ(TreeNode* root, int minVal, int maxVal,int & diff) {
        if (!root)
            return;
        diff = max(diff, max(abs(minVal - root->val), abs(maxVal - root->val)));
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        differ(root->left, minVal, maxVal,diff);
        differ(root->right, minVal, maxVal,diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        if (!root)
            return 0;
        int minVal = root->val, maxVal = root->val;
        int diff=0;
        differ(root, minVal, maxVal,diff);
        return diff;
    }


};