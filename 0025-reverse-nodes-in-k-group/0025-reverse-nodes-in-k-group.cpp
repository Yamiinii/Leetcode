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
    int length(ListNode* head)
{
	ListNode* head2=head;
	int cnt=0;
	while(head2!=NULL)
	{
		cnt++;
		head2=head2->next;
	}
	return cnt;
}

ListNode* reverseK(ListNode *head, int n,int i,int k)
{
	
	if(head==NULL || i==n)
	return head;
	
	ListNode* curr=head,*prev=NULL,*next=NULL;
	int count=0;
	while(curr!=NULL && count<k)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}

	if(curr!=NULL)
	{
		head->next=reverseK(next,n,++i,k);
	}

	return prev;
}
  ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
	return head;
      int len=length(head);
      // if(len%k==0)
      //     return head;
      int num=len/k;
      
	int i=0;
	ListNode*ans=reverseK(head,num,i,k);
	return ans;
    }
};