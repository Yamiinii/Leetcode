class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (right==1) return head;
        ListNode dummy=ListNode();
        ListNode* L=&dummy, *R;
        dummy.next=head;
        // Move L to the position left
        for(int i=0; i<left-1; i++)
            L=L->next;
        R=L->next;
        //From i=left to right, move R->next to the position right stepwise
        for(int i=left; i<right; i++){
            ListNode* rev=R->next;//Reverse the linked list (1)
            R->next=rev->next;//(2)position for R->next in next i 
            rev->next=L->next;//(3)
            L->next=rev; //(4)
        }

        return dummy.next;
    }
};