class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sum=amount;
        int n=coins.size();
         int i, j, x, y;
 
    // We need sum+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (sum = 0)
    int table[sum + 1][n];
 
    // Fill the entries for 0
    // value case (sum = 0)
    for (i = 0; i < n; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < sum + 1; i++) {
        for (j = 0; j < n; j++) {
            // Count of solutions including coins[j]
            x = (i - coins[j] >= 0) ? table[i - coins[j]][j]
                                    : 0;
 
            // Count of solutions excluding coins[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[sum][n - 1];
    }
};