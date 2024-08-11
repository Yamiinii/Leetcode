/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,   unordered_map<Node*,Node*>& mpp)
    {
        vector<Node*> adj;
        Node* clone=new Node(node->val);
        mpp[node]=clone;
          for(auto it:node->neighbors)
        {
            if(mpp.find(it)!=mpp.end())
                adj.push_back(mpp[it]);
            else
                adj.push_back(dfs(it,mpp));
        }
        clone->neighbors=adj;
        return clone;
        
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return node;
        if(node->neighbors.size()==0)
           {
           Node* clone=new Node(node->val);
           return clone;
       }
           unordered_map<Node*,Node*> mpp;
        return dfs(node,mpp);
    }
};