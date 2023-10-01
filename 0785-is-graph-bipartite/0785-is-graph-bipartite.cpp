class Solution {
public:
    //BFS
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> coloured(n, -1); // Initialize to -1
        for (int i = 0; i < n; i++) {
            if (coloured[i] == -1) {
                queue<int> q;
                q.push(i);
                coloured[i] = 0; // Start with color 0

                while (!q.empty()) {
                    int front = q.front();
                    q.pop();

                    for (int neighbor : graph[front]) {
                        if (coloured[neighbor] == -1) {
                            coloured[neighbor] = 1 - coloured[front]; // Toggle color
                            q.push(neighbor);
                        } else if (coloured[neighbor] == coloured[front]) {
                            return false; // Conflict, not bipartite
                        }
                    }
                }
            }
        }
        return true; // No conflicts, graph is bipartite
    }
};
