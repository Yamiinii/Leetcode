class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=arrays[0][0];
        int maxi=arrays[0].back();
        int dist=0;
        for(int i=1;i<arrays.size();i++)
        {
            dist=max(dist,arrays[i].back()-mini);
            dist=max(dist,maxi-arrays[i][0]);
            maxi=max(maxi,arrays[i].back());
            mini=min(mini,arrays[i][0]);
        }
        return dist;
    }
};