class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<int> in=intervals[0];
        for(int i=1;i<n;i++)
        {
           if(intervals[i][0]<=in[1])
           {
             in[1] = max(in[1], intervals[i][1]);
           }
           else
           {
            ans.push_back(in);
            in=intervals[i];
           }
        }
        ans.push_back(in);
        return ans;
    }
};