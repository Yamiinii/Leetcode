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
    int cntNodes(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = cntNodes(head);

        // Case: Remove the first node (head)
        if (n == k) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        ListNode* temp = head;

        // Case: List has only one node and we need to remove it
        if (n == k && temp->next == nullptr)
            return nullptr;

        // Move to the node just before the target
        for (int i = 0; i < k - n - 1; i++) {
            temp = temp->next;
        }

        // Case: Remove the last node
        if (n == 1) {
            ListNode* toDelete = temp->next;
            temp->next = nullptr;
            delete toDelete;
            return head;
        }

        // General case
        ListNode* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        return head;
    }
};
