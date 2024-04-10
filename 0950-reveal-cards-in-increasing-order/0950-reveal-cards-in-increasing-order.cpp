class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& v) {
        sort(v.begin(),v.end());
        vector<int> result(v.size(),0);
        result[0]=v[0];
        for(int i=1,p=0;i<v.size();i++)
        {
            for(int j=0;j<2;p%=v.size(),j+=(result[p]==0?1:0))
            {
                p++;
            }
            
            result[p]=v[i];
        }
        return result;
    }
};