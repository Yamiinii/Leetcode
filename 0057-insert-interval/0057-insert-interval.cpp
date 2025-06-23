class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<int> curr=intervals[0];
        vector<vector<int>> inter;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]<=curr[1])
            {
                curr[1]=max(curr[1],intervals[i][1]);
            }
            else
            {
                inter.push_back(curr);
                curr=intervals[i];
            }
        }

        inter.push_back(curr);

        return inter;
    }
};