class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k,int v)
    {
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
private:
    int cap;
    unordered_map<int,Node*> mpp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
public:
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addNode(Node* newnode)
    {
        Node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    void delNode(Node* deletenode)
    {
        Node* delprev=deletenode->prev;
        Node* delnext=deletenode->next;
        
        delprev->next=delnext;
        delnext->prev=delprev;
        //delete(deletenode);
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end())
        {
            Node* existing=mpp[key];
            int res=existing->value;
            mpp.erase(key);
            delNode(existing);
            addNode(existing);
            mpp[key]=head->next;
            return res;
            
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end())
        {
            Node* existing=mpp[key];
            mpp.erase(key);
            delNode(existing);
        }
        if(mpp.size()==cap)
        {
            mpp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(new Node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */