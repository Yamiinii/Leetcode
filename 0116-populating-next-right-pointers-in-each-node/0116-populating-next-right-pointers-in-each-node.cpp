#include <queue>

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root; // Handle the case where the root is null
        
        std::queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size(); // Get the number of nodes at the current level
            
            for (int i = 0; i < size; ++i) {
                Node* front = q.front();
                q.pop();
                
                // Connect to the next node in the queue if it's not the last node
                if (i < size - 1) {
                    front->next = q.front(); // Connect to the next node
                } else {
                    front->next = NULL; // Last node in this level points to NULL
                }

                // Push left and right children to the queue
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
        }
        
        return root;
    }
};
