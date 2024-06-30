class Solution {
public:
    //i j ===>j n-i-1-->brute
    //for optimal lets take transpose of the matrix and then reverse the rows
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
     
                    swap(matrix[i][j],matrix[j][i]);
    
            }
        }
        
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};