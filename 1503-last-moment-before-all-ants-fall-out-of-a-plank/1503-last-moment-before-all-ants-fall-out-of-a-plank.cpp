class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxTime = 0;
        for (int l : left) {
            maxTime = max(maxTime, l);
        }
        for (int r : right) {
            maxTime = max(maxTime, n - r);
        }
        return maxTime;
    }
};
