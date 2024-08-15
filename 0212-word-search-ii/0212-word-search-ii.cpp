class Trie{
    public:
    Trie* links[26];
    bool isword=false;
};

class Solution {
public:
    
    int dir[5]={-1,0,1,0,-1};
    
    void addword(Trie* curr,string word)
    {
        for(auto ch:word)
        {
            if(!curr->links[ch-'a'])
                curr->links[ch-'a']=new Trie();
            curr=curr->links[ch-'a'];
        }
        
        curr->isword=true;
    }
    
    void dfs(vector<string>& ans, string ds, Trie* curr, int i, int j,vector<vector<char>>& board,vector<vector<bool>> &vis)
    {
        if(!curr)
            return;
        
        if(curr->isword)
        {
            ans.push_back(ds);
            curr->isword=false;
        }
        
        vis[i][j]=true;
        
        for(int del=0;del<4;del++)
        {
            int next_i=i+dir[del],next_j=j+dir[del+1];
            if(next_i<board.size() && next_j<board[0].size() && !vis[next_i][next_j] && curr->links[board[next_i][next_j]-'a'])
            {
                dfs(ans, ds + board[next_i][next_j],curr->links[board[next_i][next_j] - 'a'], next_i, next_j,board,vis);
            }
        }
         vis[i][j]= false; 
        
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie=new Trie();
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(auto word:words)
            addword(trie,word);
        
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char ch=board[i][j];
                if(trie->links[ch-'a'])
                    dfs(ans,string(1,ch),trie->links[ch-'a'],i,j,board,visited);
            }
        }
        return ans;
    }
};