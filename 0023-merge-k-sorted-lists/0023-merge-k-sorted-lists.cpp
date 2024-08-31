class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // Min-heap based on node value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        // Push the head of each list into the priority queue
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        ListNode* dummy = new ListNode();  // Dummy node to act as a placeholder
        ListNode* current = dummy;
        
        // Process the priority queue
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            current->next = node;  // Link the smallest node to the result
            current = current->next;  // Move the pointer
            if (node->next) {
                pq.push(node->next);  // Push the next node from the same list
            }
        }
        
        ListNode* result = dummy->next;  // Skip the dummy node
        delete dummy;  // Free the dummy node
        return result;
    }
};
