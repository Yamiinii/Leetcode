// Pass by Reference:
// Instead of passing the vector by value, pass it by reference to avoid unnecessary copying.

// Use an Array Instead of Map:
// Since the values in the tree are integers, you can use an array to keep track of the frequency of each digit. This can be more efficient than using an unordered map.

// Avoid Recreating Frequency Map:
// Instead of recreating the frequency map for each path, update it incrementally as you traverse the tree.
class Solution {
public:
    bool check(vector<int>& freq) {
        int oddCount = 0;
        for (int count : freq) {
            if (count % 2 != 0) {
                oddCount++;
            }
        }
        return oddCount <= 1;
    }

    void recursion(TreeNode* root, vector<int>& freq, int& count) {
        if (root == nullptr) {
            return;
        }

        freq[root->val]++;

        if (root->left == nullptr && root->right == nullptr) {
            if (check(freq)) {
                count++;
            }
        }

        recursion(root->left, freq, count);
        recursion(root->right, freq, count);

        freq[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0;
        vector<int> freq(10, 0); // Assuming values are in the range [1, 9]
        recursion(root, freq, count);
        return count;
    }
};