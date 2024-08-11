#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

class Solution {
public:
    std::string frequencySort(std::string s) {
        int n = s.size();
        std::unordered_map<char, int> mpp;
        // Count frequencies of each character
        for (char ch : s) {
            mpp[ch]++;
        }

        // Max-heap based on frequency
        std::priority_queue<std::pair<int, char>> pq;
        // Push all characters and their frequencies into the max-heap
        for (auto& it : mpp) {
            pq.push({it.second, it.first});
        }

        std::string result;
        // Build the result string based on the max-heap
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            result.append(p.first, p.second); // Append 'p.first' occurrences of 'p.second'
        }

        return result;
    }
};
