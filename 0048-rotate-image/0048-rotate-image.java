class Solution {
    private void reverse(int[] row)
    {
        int left=0;
        int right=row.length-1;
        while(left<right)
        {
            int temp=row[right];
            row[right]=row[left];
            row[left]=temp;
            left++;
            right--;
        }
    }
    public void rotate(int[][] matrix) {
        int n=matrix.length;
        int m=matrix[0].length;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                int num=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=num;
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i]);
        }
    }
}