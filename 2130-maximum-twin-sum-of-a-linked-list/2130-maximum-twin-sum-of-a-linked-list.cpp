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
    ListNode *GetMiddle(ListNode *Head)
    {
        ListNode *Slow = Head;
        ListNode *Fast = Head;

        while (Fast != NULL && Fast->next != NULL)
        {
            Slow = Slow->next;
            Fast = Fast->next->next;
        }

        return Slow;
    }

    //****************************************************
    ListNode *ReverseLL(ListNode *Head)
    {
        ListNode *Current = Head;
        ListNode *Previous = NULL;
        ListNode *Forward = NULL;

        while (Current != NULL)
        {
            Forward = Current->next;
            Current->next = Previous;
            Previous = Current;
            Current = Forward;
        }

        return Previous;
    }

    //****************************************************
    int pairSum(ListNode *head)
    {

        ListNode *Middle = GetMiddle(head);
        ListNode *SecondHalfReverse = ReverseLL(Middle);

        ListNode *head1 = head;
        ListNode *head2 = SecondHalfReverse;

        int ans = 0;

        while (head2 != NULL)
        {
            int sum = head1->val + head2->val;
            ans = max(ans, sum);
            head1 = head1->next;
            head2 = head2->next;
        }

        return ans;
    }
};