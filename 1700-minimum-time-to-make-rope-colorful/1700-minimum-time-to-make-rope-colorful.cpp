class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime = 0;
        int n = colors.size();

        for (int i = 1; i < n; ++i) {
            // If current and previous are the same color
            if (colors[i] == colors[i - 1]) {
                // Remove the one with smaller time
                if (neededTime[i] < neededTime[i - 1]) {
                    totalTime += neededTime[i];
                    // Keep the more expensive one for future comparisons
                    neededTime[i] = neededTime[i - 1];
                } else {
                    totalTime += neededTime[i - 1];
                }
            }
        }

        return totalTime;
    }
};
