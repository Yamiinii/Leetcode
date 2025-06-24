class Solution {
    //Best solution
    public void setZeroes(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        int col0=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    //mark row 0
                    matrix[i][0]=0;

                    //mark col 0
                    if(j!=0)
                    matrix[0][j]=0;
                    else
                    col0=0;
                }
            }
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]!=0)
                {
                    if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
                }
            }
        }

        //now for first row and col
        if(matrix[0][0]==0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[0][i]=0;
            }
        }

        if (col0==0)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][0]=0;
            }
        }

    }
}