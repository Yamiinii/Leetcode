class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        // Create the adjacency list with Manhattan distances
        vector<vector<pair<int, int>>> adj(n); // Each node's neighbors and their distances
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        
        // Now you have the adjacency list with Manhattan distances
        // Implement Prim's algorithm to find MST using your existing code
        
        // The rest of your code with Prim's algorithm can go here...
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n, 0);
        pq.push({0, 0});
        int sum = 0;
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wght = it.first;
            int node = it.second;
            
            if (vis[node] == 1)
                continue;
            
            vis[node] = 1;
            sum += wght;
            
            for (auto i : adj[node]) {
                int adjNode = i.first;
                int adjWeight = i.second;
                if (!vis[adjNode]) {
                    pq.push({adjWeight, adjNode});
                }
            }
        }
        
        return sum;
    }
};
