/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        if(root==NULL)
        return "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL)
            ss<<"#,";
            else
            {
                ss<<front->val<<",";
                q.push(front->left);
                q.push(front->right);
            }
        }

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
     
        if(data.empty())
        return NULL;
          stringstream ss(data);
        string s;

        getline(ss,s,',');
        if(s=="#")
        return NULL;

        TreeNode* root=new TreeNode(stoi(s));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front=q.front();
            q.pop();
            getline(ss,s,',');
            if(s!="#")
            {
                front->left=new TreeNode(stoi(s));
                q.push(front->left);
            }
            getline(ss,s,',');
              if(s!="#")
            {
                front->right=new TreeNode(stoi(s));
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));