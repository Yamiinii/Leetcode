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
    int cntNodes(ListNode* head)
    {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k=cntNodes(head);
        //case of 1st node
        if(n==k)
        {
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
     
        ListNode* temp=head;
        //case of last node
        if(n==k && temp->next==NULL)
        return NULL;
    
        for(int i=0;i<k-n-1;i++)
        {
            temp=temp->next;
        }
            if(n==1)
        {
            ListNode* d=temp->next;
            temp->next=NULL;
            delete d;
            return head;
        }
        
        //case of general node
        ListNode* nextt=temp->next->next;
        ListNode* d=temp->next;
        temp->next=nextt;
        delete d;

        return head;
    }
};