class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false; // No cycle if the list is empty or has only one node.
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // Cycle detected.
            }
        }

        return false; // No cycle found.
    }
};
