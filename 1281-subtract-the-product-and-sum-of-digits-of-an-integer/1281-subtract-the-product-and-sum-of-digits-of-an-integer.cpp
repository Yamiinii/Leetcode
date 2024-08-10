class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> ans;
        while (n > 0)
        {
            ans.push_back(n % 10);
            n /= 10;
        }
        int product = 1;
        int sum = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            product *= ans[i];
            sum += ans[i];
        }
        return product - sum;
    }
};