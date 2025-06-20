/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int cnt(ListNode head)
    {
        ListNode temp=head;
        int cnt=0;
        while(temp!=null)
        {
            cnt++;
            temp=temp.next;
        }

        return cnt;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        int k=cnt(head);
        ListNode temp=head;
        if(n==k && temp.next==null)
        return null;
        if(n==k)
        {
            ListNode newhead=temp.next;
            return newhead;
        }

        for(int i=0;i<k-n-1;i++)
        {
            temp=temp.next;
        }

        if(n==1)
        {
            temp.next=null;
            return head;
        }

        ListNode next=temp.next.next;
        temp.next=next;

        return head;
    }
}