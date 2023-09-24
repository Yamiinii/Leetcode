class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double matrix[101][101] = {0.0};
        matrix[0][0]=poured;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(matrix[i][j]>1)
                {
                    matrix[i+1][j]+=(matrix[i][j]-1)/2.0;
                    matrix[i+1][j+1]+=(matrix[i][j]-1)/2.0;
                    matrix[i][j]=1.0;
                }
            }
        }
        return matrix[query_row][query_glass];
    }
};