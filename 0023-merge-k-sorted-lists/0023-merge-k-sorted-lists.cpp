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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
          priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
              for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        ListNode* ans=new ListNode();
        ListNode* dummy=ans;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            dummy->next = node;  // Link the smallest node to the result
            dummy = dummy->next;  // Move the pointer
            if (node->next) {
                pq.push(node->next);  // Push the next node from the same list
            }
        }
        return ans->next;
    }
};