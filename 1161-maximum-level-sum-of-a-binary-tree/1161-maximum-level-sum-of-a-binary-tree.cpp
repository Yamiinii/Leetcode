class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxi=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        int ans=1;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            while(n--){
                auto temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->right!=NULL){
                  q.push(temp->right);
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
            }
            if(sum>maxi){
                maxi=sum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};