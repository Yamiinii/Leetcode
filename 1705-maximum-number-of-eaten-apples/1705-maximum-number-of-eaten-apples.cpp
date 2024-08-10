class Solution {
public:
    int eatenApples(std::vector<int>& apples, std::vector<int>& days) {
        int day = 1; // Start from day 0
        int ans = 0;
        // Min-heap to store pairs of (expiration day, apples count)
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for (int i = 0; i < apples.size() || !pq.empty(); ++i) {
            if (i < days.size()) { // Check if i is within bounds
                pq.push({i + days[i], apples[i]});
            }

            // Remove expired apples
            while (!pq.empty() && pq.top().first <= i) {
                pq.pop();
            }

            // Eat apples if there are any valid apples
            if (!pq.empty()) {
                auto top = pq.top();
                pq.pop();
                ans++;
                if (--top.second > 0) {
                    pq.push(top); // Push back with reduced count
                }
            }
            day++;
        }

        return ans;
    }
};
