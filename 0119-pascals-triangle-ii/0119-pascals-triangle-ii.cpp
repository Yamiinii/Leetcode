class Solution {
public:
    vector<int> row(int rowIndex)
    {
         vector<int> v;
        long long res=1;
        v.push_back(1);
        for(int i=1;i<rowIndex;i++)
        {
            res=res*(rowIndex-i);
            res=res/i;
            v.push_back(res);
        }
        return v;
    }
    vector<int> getRow(int rowIndex) {
       return row(rowIndex+1);
       
    }
};