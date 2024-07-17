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
    bool check(ListNode* L1,ListNode* L2)
    {
        while(L1 &&L2)
        {
            if(L1->val!=L2->val)
                return false;
            L1=L1->next;
            L2=L2->next;
        }
        return true;
    }
    
    ListNode* rev(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* next=NULL;
        ListNode* prev=NULL;
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
         if (!head || !head->next) return true; // Edge case

        // Step 1: Find the middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* reversedHalf = rev(slow);

        // Step 3: Compare the first half and the reversed second half
        return check(head, reversedHalf);
    }
};