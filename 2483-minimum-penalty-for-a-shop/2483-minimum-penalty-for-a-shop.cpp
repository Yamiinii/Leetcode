class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> cumulativeN(n + 1, 0);
        vector<int> cumulativeY(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            cumulativeN[i + 1] = cumulativeN[i] + (customers[i] == 'N');
            cumulativeY[i + 1] = cumulativeY[i] + (customers[i] == 'Y');
        }
        
        int bestClosing = -1;
        int minPenalty = n; // Initialize to a value larger than possible penalties
        
        for (int i = 0; i <= n; i++) {
            int penalty = cumulativeN[i] + cumulativeY[n] - cumulativeY[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestClosing = i;
            }
        }
        
        return bestClosing;
    }
};
