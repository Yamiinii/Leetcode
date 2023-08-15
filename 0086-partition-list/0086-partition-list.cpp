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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessHead(0); // Dummy node for nodes with values less than x
        ListNode moreHead(0); // Dummy node for nodes with values greater than or equal to x
        ListNode *lessPtr = &lessHead; // Pointer to the last node with value less than x
        ListNode *morePtr = &moreHead; // Pointer to the last node with value greater than or equal to x

        while (head != nullptr) {
            if (head->val < x) {
                lessPtr->next = head;
                lessPtr = lessPtr->next;
            } else {
                morePtr->next = head;
                morePtr = morePtr->next;
            }
            head = head->next;
        }

        // Connect the two partitions and set the last node's next to nullptr
        lessPtr->next = moreHead.next;
        morePtr->next = nullptr;

        return lessHead.next;
    }
};
