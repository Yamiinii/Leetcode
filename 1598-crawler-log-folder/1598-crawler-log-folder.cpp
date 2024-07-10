class Solution {
public:
int minOperations(vector<string>& logs) {
        int ans=0;
        for(string s:logs){
            if(s=="../") ans--;
            else if(s=="./") ans;
            else ans++;
            
            if(ans<0) ans=0;
        }
        if(ans<0) ans=0;
        
        return ans;
    }
};