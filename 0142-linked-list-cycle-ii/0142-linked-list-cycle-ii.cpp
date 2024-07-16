class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return NULL; // No cycle if the list is empty or has only one node.
        }

        ListNode* slow = head; // Tortoise
        ListNode* fast = head; // Hare

        while (fast && fast->next) {
            slow = slow->next;          // Move slow by 1
            fast = fast->next->next;   // Move fast by 2

            if (slow == fast) { // Cycle detected
                // Find the entrance to the cycle
                ListNode* entry = head; // Start from head
                while (entry != slow) {
                    entry = entry->next; // Move one step at a time
                    slow = slow->next;    // Move slow to find the entrance
                }
                return entry; // Entry point of the cycle
            }
        }

        return NULL; // No cycle found
    }
};
