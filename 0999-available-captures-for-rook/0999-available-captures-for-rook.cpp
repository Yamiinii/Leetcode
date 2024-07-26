class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int ii=0,jj=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    ii=i;
                    jj=j;
                    break;
                }
            }
        }
        int count=0;
        for(int i=ii;i>=0;i--){
            if(board[i][jj]=='p'){
                count++;
                break;
            }
            else if(board[i][jj]=='B')
                break;
        }
        for(int i=ii;i<8;i++){
            if(board[i][jj]=='p'){
                count++;
                break;
            }
            else if(board[i][jj]=='B')
                break;
        }
        for(int j=jj;j<8;j++){
            if(board[ii][j]=='p'){
                count++;
                break;
            }
            else if(board[ii][j]=='B')
                break;
        }
        for(int j=jj;j>=0;j--){
            if(board[ii][j]=='p'){
                count++;
                break;
            }
            else if(board[ii][j]=='B')
                break;
        }
        return count;

    }
};