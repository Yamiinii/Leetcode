class Solution {
public:
    //linear graphs with no cycle are always biparatite
    //colouring adj differently
    //any graph even length cycle
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(),-1);
    for (int start = 0; start < graph.size(); ++start) {
            if (colors[start] == -1) { // If this node hasn't been colored yet
                queue<int> q;
                q.push(start);
                colors[start] = 0; // Start coloring with 0

                while (!q.empty()) {
                    int front = q.front();
                    q.pop();

                    for (auto adj : graph[front]) {
                        if (colors[adj] == -1) {
                            // Color with the opposite color of the current node
                            colors[adj] = !colors[front];
                            q.push(adj);
                        } else if (colors[adj] == colors[front]) {
                            // If adjacent node has the same color, it's not bipartite
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};