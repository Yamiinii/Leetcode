class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        // Sort the intervals based on the end time (second element)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int cnt = 0;
        int end = intervals[0][1]; // Initialize the first end time
        
        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval overlaps with the previous one
            if (intervals[i][0] < end) {
                cnt++;
            } else {
                end = intervals[i][1]; // Update the end time for the next non-overlapping interval
            }
        }
        
        return cnt;
    }
};
