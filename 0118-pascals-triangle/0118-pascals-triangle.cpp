class Solution {
public:

    vector<int> genRow(int i)
    {
        vector<int> v;
       long long res=1;
        v.push_back(1);
        for(int j=1;j<i;j++)
        {
            res=res*(i-j);
            res=res/j;
            v.push_back(res);
        }
        return v;

    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> rowlist=genRow(i);
            ans.push_back(rowlist);
        }
        return ans;
    }
};