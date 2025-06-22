class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int left=0;
        int right=matrix[0].length-1;
        int top=0;
        int bottom=matrix.length-1;
        List<Integer> l = new ArrayList<Integer>();
        while(left<=right && top<=bottom)
        {
            for(int i=left;i<=right;i++)
            {
                l.add(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                l.add(matrix[i][right]);
            }
            right--;
           // Traverse bottom row if still within bounds
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    l.add(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse left column if still within bounds
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    l.add(matrix[i][left]);
                }
                left++;
            }
        }

        return l;
    }
}