class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int tail = 0;
        int ans = 0;
        int n = s.size();

        for (int head = 0; head< n; head++) {
            maxCost -= abs(s[head] - t[head]); // Calculate the cost of current characters

            while (maxCost < 0) {
                // If the cost exceeds maxCost, move the left pointer 'i' to shrink the window
                maxCost += abs(s[tail] - t[tail]);
                tail++;
            }

            ans = max(ans, head - tail + 1); // Update the maximum window length we've found so far
        }

        return ans;
    }
};
