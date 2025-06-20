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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            pq.push({lists[i]->val,lists[i]});
        }

        ListNode* head=new ListNode(-1);
        ListNode* temp=head;

        while(!pq.empty())
        {
            pair<int,ListNode*> front=pq.top();
            temp->next=front.second;
            pq.pop();

            if(front.second->next)
            {
                pq.push({front.second->next->val,front.second->next});
            }

            temp=temp->next;
        }

        return head->next;
    }
};