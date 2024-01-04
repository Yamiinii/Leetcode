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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int carry = 0;
    ListNode* newList = new ListNode(-1); // Dummy node
    ListNode* dummy = newList;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10; // Determine carry
        dummy->next = new ListNode(sum % 10); // Create new node with remainder of sum
        dummy = dummy->next; // Move dummy forward

        // Move l1 and l2 pointers if not nullptr
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return newList->next; 
            
    }
};