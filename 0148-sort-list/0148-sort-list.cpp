/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* divide(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;

        // Use slow and fast pointers to find the middle
        while (fast != NULL && fast->next != NULL) {
            pre = slow;           // Track the previous node
            slow = slow->next;    // Move slow pointer one step
            fast = fast->next->next; // Move fast pointer two steps
        }

        // Split the list into two halves
        if (pre != NULL) {
            pre->next = NULL; // Terminate the first half
        }
        
        return slow; // Return the starting node of the second half
    }

    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* nh = new ListNode(0); // Dummy node
        ListNode* du = nh;

        while (l1 != NULL || l2 != NULL) {
            if (l2 == NULL || (l1 != NULL && l1->val < l2->val)) {
                du->next = l1; // Attach l1 to the merged list
                du = du->next; // Move the dummy pointer
                l1 = l1->next; // Move l1 pointer
            } else {
                du->next = l2; // Attach l2 to the merged list
                du = du->next; // Move the dummy pointer
                l2 = l2->next; // Move l2 pointer
            }
        }

        return nh->next; // Return the merged list, skipping dummy node
    }
    
    // Function to sort the linked list
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head; // Base case: if list is empty or has one node
        }
        
        ListNode* back = divide(head); // Divide the list
        ListNode* left = sortList(head); // Sort the first half
        ListNode* right = sortList(back); // Sort the second half

        return merge(left, right); // Merge the sorted halves
    }
};