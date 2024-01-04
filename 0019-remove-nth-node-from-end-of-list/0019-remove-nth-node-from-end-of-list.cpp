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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            num++;
            temp=temp->next;
        }
        if(n==num)
        {
           ListNode* tempNode = head;
    head = head->next;
    delete tempNode;
    return head;
        }
        
        ListNode* temp2=head;
        for(int i=1;i<num-n;i++)
        {
            temp2=temp2->next;
        }
        ListNode* del=temp2->next;
        temp2->next=temp2->next->next;
        delete del;
        
        return head;
    }
};