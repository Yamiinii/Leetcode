class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<tuple<int, int, int>> q; // {node, state, distance}
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        // Initialize the queue with starting nodes and states.
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i, 0});
            visited[i][1 << i] = true;
        }

        while (!q.empty()) {
            auto [node, state, distance] = q.front();
            q.pop();

            // If all nodes are visited, return the distance.
            if (state == (1 << n) - 1) {
                return distance;
            }

            // Explore neighboring nodes.
            for (int neighbor : graph[node]) {
                int next_state = state | (1 << neighbor);

                // If the state has not been visited, enqueue it.
                if (!visited[neighbor][next_state]) {
                    q.push({neighbor, next_state, distance + 1});
                    visited[neighbor][next_state] = true;
                }
            }
        }

        return -1; // Not reachable.
    }
};
