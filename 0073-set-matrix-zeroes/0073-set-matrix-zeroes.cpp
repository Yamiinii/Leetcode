class Solution {
public:
    void markCol(vector<vector<int>>& matrix,int i,int m)
    {
        for(int row=0;row<m;row++)
        {
            if(matrix[row][i]!=0)
                matrix[row][i]=-999999;
        }
    }
    
    void markRow(vector<vector<int>>& matrix,int i,int m)
    {
        for(int col=0;col<m;col++)
        {
            if(matrix[i][col]!=0)
                matrix[i][col]=-999999;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        //brute
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    markRow(matrix,i,m);
                    markCol(matrix,j,n);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==-999999)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};