class Solution {
    public boolean wordFormed(char[][] board, String word,int idx,int i,int j,boolean[][] visited)
    {
        if(idx==word.length())
        return true;

        if(i<0 || j<0 ||i>=board.length || j>=board[0].length || idx>word.length() || board[i][j]!=word.charAt(idx)||visited[i][j])
        return false;

        visited[i][j]=true;

        boolean found = wordFormed(board, word, idx + 1, i + 1, j, visited) ||
                wordFormed(board, word, idx + 1, i, j + 1, visited) ||
                wordFormed(board, word, idx + 1, i - 1, j, visited) ||
                wordFormed(board, word, idx + 1, i, j - 1, visited);


        visited[i][j]=false;

        return found;
    }

    public boolean exist(char[][] board, String word) {
        int n=board.length;
        int m=board[0].length;
        int len=word.length();
        boolean[][] visited=new boolean[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word.charAt(0) && wordFormed(board,word,0,i,j,visited))
                return true;
            }
        }

        return false;
    }
}