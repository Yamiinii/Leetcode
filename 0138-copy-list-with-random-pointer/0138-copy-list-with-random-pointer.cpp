/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==nullptr)
        return nullptr;
        Node* iter=head;
        Node* front=head;
        while(iter!=NULL)
        {
            front=iter->next;
            Node* copynode=new Node(iter->val);
            iter->next=copynode;
            copynode->next=front;
            iter=front;
        }

     iter=head;
        while(iter!=NULL)
        {
            if(iter->random!=NULL)
            {
                iter->next->random=iter->random->next;
               
            }
             iter=iter->next->next;
        }

        Node* pseudoNode=new Node(0);
        Node* copy=pseudoNode;
        iter=head;
        while(iter!=nullptr)
        {
            Node* front=iter->next->next;
            copy->next=iter->next;
            iter->next=front;
            copy=copy->next;
            iter=front;
        }
        return pseudoNode->next;
    }
};