#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Color array to track the color assigned to each node
        
        // Iterate over all nodes to handle disconnected components
        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) { // If the node is not colored
                queue<int> q;
                q.push(start);
                color[start] = 0; // Start coloring the node with color 0

                while (!q.empty()) {
                    int front = q.front();
                    q.pop();

                    for (auto neighbor : graph[front]) {
                        if (color[neighbor] == -1) { // If the neighbor has not been colored
                            color[neighbor] = !color[front]; // Color with opposite color
                            q.push(neighbor);
                        } else if (color[neighbor] == color[front]) { // Check for conflict
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};
