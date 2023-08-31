#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    struct Interval {
        int start;
        int end;
        Interval(int s, int e) : start(s), end(e) {}
    };

    static bool compareIntervals(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }

    int minTaps(int n, std::vector<int>& ranges) {
        std::vector<Interval> intervals;
        for (int i = 0; i <= n; i++) {
            int start = std::max(0, i - ranges[i]);
            int end = std::min(n, i + ranges[i]);
            intervals.push_back(Interval(start, end));
        }
        std::sort(intervals.begin(), intervals.end(), compareIntervals);

        int i = 0;
        int currEnd = 0;
        int nextEnd = 0;
        int taps = 0;

        while (i < intervals.size() && currEnd < n) {
            while (i < intervals.size() && intervals[i].start <= currEnd) {
                nextEnd = std::max(nextEnd, intervals[i].end);
                i++;
            }
            if (nextEnd == currEnd) {
                return -1; // No progress can be made
            }
            currEnd = nextEnd;
            taps++;
        }

        return currEnd >= n ? taps : -1;
    }
};
