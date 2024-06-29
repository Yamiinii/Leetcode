class Solution {
public:
    //for a specific position using (n-1)C(r-1)
    //it is found using num=num*(num-1)
    //num/i+1
    //for a complete row we see the trend as val=prev*(row-col)/col
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> v1;
        v1.push_back(1);
        ans.push_back(v1);
        if(numRows==1)
            return ans;
        
        for(int i=1;i<numRows;i++)
        {
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<i;j++)
            {
               v.push_back(ans[i-1][j-1]+ans[i-1][j]);   
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};