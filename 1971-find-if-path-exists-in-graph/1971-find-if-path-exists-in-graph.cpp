#include <vector>
#include <queue>
#include <unordered_set>

class Solution {
public:
    bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
        std::unordered_set<int> visited;
        std::queue<int> q;
        q.push(source);
        visited.insert(source);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == destination) {
                return true;
            }

            for (auto& edge : edges) {
                if (edge[0] == curr && visited.find(edge[1]) == visited.end()) {
                    q.push(edge[1]);
                    visited.insert(edge[1]);
                }
                if (edge[1] == curr && visited.find(edge[0]) == visited.end()) {
                    q.push(edge[0]);
                    visited.insert(edge[0]);
                }
            }
        }

        return false;
    }
};
