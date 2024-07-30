class Node{
    public:
    Node* links[26];
    bool flag=false;
    
    bool isPresent(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    
    Node* get(char ch){
        return links[ch-'a'];}
    
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    
    bool isend()
     {   return flag;}
    
    void setend()
      {  flag=true;}
    
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(!node->isPresent(ch))
            {
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }
        node->setend();
    }
    
    bool search(string word) {
             Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(!node->isPresent(ch))
            {
                return false;
            }
            node=node->get(ch);
        }
        return node->isend();
    }
    
    bool startsWith(string word) {
             Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(!node->isPresent(ch))
            {
                return false;
            }
            node=node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */