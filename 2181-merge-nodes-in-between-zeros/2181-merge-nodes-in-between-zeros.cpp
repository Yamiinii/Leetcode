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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* nextsum=temp;
        while(nextsum!=NULL)
        {
            int sum=0;
            while(nextsum->val!=0)
            {
                sum+=nextsum->val;
                nextsum=nextsum->next;
            }
                    temp->val=sum;
        nextsum=nextsum->next;
        temp->next=nextsum;
        temp=temp->next;
        }

        return head->next;
    }
};