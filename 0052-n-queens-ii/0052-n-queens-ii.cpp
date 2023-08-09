class Solution {
public:
    bool isSafe(int row,int col,vector<string>&board,int n)
    {
        int duprow=row;
        int dupcol=col;
        
        while(row>=0 && col>=0)
              {
                    if(board[row][col]=='Q')
                       return false;
                       
                       row--;
                       col--;
              }
                       
       row=duprow;
        col=dupcol;
        
        while(col>=0)
              {
                    if(board[row][col]=='Q')
                       return false;
                       col--;
              }
                       
         row=duprow;
        col=dupcol;
        
         while(row<n&& col>=0)
              {
                    if(board[row][col]=='Q')
                       return false;
                       
                       row++;
                       col--;
              }
                       
                       return true
                      ;
    }
    
    void solve(int col,vector<string>&board, vector<int>&ans,int n)
    {
        if(col==n)
        {
            ans.push_back(1);
            return ;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
         vector<int> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans.size();
    }
};