// class Solution {
// public:
//     int rec(vector<vector<int>>& matrix,int i,int j,int n ,int m,int &cnt)
//     {
//         if(i>=n || j>=m || matrix[i][j]==0)
//         return 0;

//         //calculating the max size
//         int right=rec(matrix,i,j+1,n,m,cnt);
//         int down=rec(matrix,i+1,j,n,m,cnt);
//         int diagonal=rec(matrix,i+1,j+1,n,m,cnt);

//         int size=1+min(right,min(down,diagonal));
//         cnt+=size;

//         return size;
        

//     }

//     int countSquares(vector<vector<int>>& matrix) {
//         int cnt=0;
//         int n=matrix.size();
//         int m=matrix[0].size();
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(matrix[i][j]==1)
//                 {
//                     rec(matrix,i,j,n,m,cnt);
//                 }
//             }
//         }

//         return cnt;
//     }
// };
class Solution {
public:
    int rec(vector<vector<int>>& matrix, int i, int j, int n, int m,vector<vector<int>> &dp) {
        if (i >= n || j >= m || matrix[i][j] == 0)
            return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        // Compute sizes of squares from right, down, and diagonal
        int right = rec(matrix, i, j + 1, n, m,dp);
        int down = rec(matrix, i + 1, j, n, m,dp);
        int diagonal = rec(matrix, i + 1, j + 1, n, m,dp);

        // Current square size is 1 + min of the three
        return dp[i][j]=1 + min({right, down, diagonal});
    }

    int countSquares(vector<vector<int>>& matrix) {
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt += rec(matrix, i, j, n, m,dp);  // Add only the total size once per cell
            }
        }

        return cnt;
    }
};
