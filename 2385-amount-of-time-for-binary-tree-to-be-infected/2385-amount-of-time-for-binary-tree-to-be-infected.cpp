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
    
   void convert(TreeNode* current, int parent, unordered_map<int, unordered_set<int>>& map) {
    if (!current) return;

    // Create an entry for the current node if it doesn't exist in the map
    if (map.find(current->val) == map.end()) {
        map[current->val] = unordered_set<int>();
    }

    // Get the adjacent list for the current node
    unordered_set<int>& adjacentList = map[current->val];

    // Insert the parent node value if it's not zero (root node has parent as 0)
    if (parent != 0) {
        adjacentList.insert(parent);
    }

    // Insert the left and right child values if they exist
    if (current->left) {
        adjacentList.insert(current->left->val);
    }
    
    if (current->right) {
        adjacentList.insert(current->right->val);
    }

    // Recursively convert left and right subtrees
    convert(current->left, current->val, map);
    convert(current->right, current->val, map);
}

    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,unordered_set<int>> map;
        convert(root,0,map);
        queue<int> q;
        q.push(start);
        int minute=0;
        unordered_set<int> visited;
        visited.insert(start);
        while(!q.empty())
        {
            int levelsize=q.size();
            while(levelsize>0)
            {
                int current=q.front();
                q.pop();
                
                for(int num:map[current])
                {
                    if(visited.find(num)==visited.end())
                    {
                        visited.insert(num);
                        q.push(num);
                    }
                }
                levelsize--;
            }
            
            minute++;
        }
        return minute-1;
        
    }
};