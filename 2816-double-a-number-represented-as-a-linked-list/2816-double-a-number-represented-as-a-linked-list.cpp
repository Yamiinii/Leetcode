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
    ListNode* reverseList(ListNode* head){
        ListNode* ptr = head, *fptr = ptr->next, *dptr;
        if(fptr) dptr = fptr->next;
        if(fptr) fptr->next = ptr; 
        ptr->next = NULL; ptr = fptr; fptr = dptr; 
        while(ptr && fptr){
            dptr = fptr->next;
            fptr->next = ptr;
            ptr = fptr; fptr = dptr;
        }
        return ptr?ptr:head;
    }
    
    ListNode* doubleIt(ListNode* head) {
        head = reverseList(head);
        int carry = 0;
        for(ListNode* ptr = head; ptr; ptr = ptr->next){
            int t = ptr->val*2;
            ptr->val = (t + carry)%10;
            carry = (t + carry)/10;
            if( !ptr->next && carry) { ptr->next = new ListNode(carry); ptr = ptr->next; }
        }
        return reverseList(head);
    }
};
