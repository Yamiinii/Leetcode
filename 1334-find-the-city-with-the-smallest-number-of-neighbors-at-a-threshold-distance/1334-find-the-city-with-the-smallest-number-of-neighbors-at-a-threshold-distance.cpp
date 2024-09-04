class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
   vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Distance to itself is 0
        for(int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        
        // Fill in the initial distances from the edges
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w; // assuming undirected graph
        }
        
        // Floyd-Warshall algorithm to find shortest paths
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        // Find the city with the smallest number of reachable cities
        int minReachable = n; // initialize with max possible value
        int cityWithMinReachable = -1;
        
        for(int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for(int j = 0; j < n; ++j) {
                if(dist[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            
            // Choose the city with the smallest reachable count, 
            // and if there's a tie, choose the city with the larger index
            if(reachableCount <= minReachable) {
                minReachable = reachableCount;
                cityWithMinReachable = i;
            }
        }
        
        return cityWithMinReachable;
    }
};