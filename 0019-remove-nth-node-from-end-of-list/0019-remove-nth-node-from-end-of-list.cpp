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
        int count=0;
        int i=0;
        ListNode* temp1=head;
        while(temp1!=NULL)
        {
            i++;
            temp1=temp1->next;
        }
             if(i==n)
        {
           ListNode* tempNode = head;
    head = head->next;
    delete tempNode;
    return head;
        }
ListNode* temp2=head;
        for(int j=1;j<i-n;j++)
        {
            temp2=temp2->next;
        }
        ListNode* del=temp2->next;
        temp2->next=temp2->next->next;
        delete del;
        
        return head;
    }
};