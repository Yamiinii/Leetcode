class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
              vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].emplace_back(v, w);
        }
           queue<tuple<int, int, int>> q;
        q.push({0, src, 0});
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        while(!q.empty())
        {
            auto [stops,node,val]=q.front();
            q.pop();
            if(stops>k)
                continue;
            // if(node==dst)
            //     return val;
           for (const auto& [neighbor, weight] : adj[node]) {
                if (val + weight < dist[neighbor] && stops <= k) {
                    dist[neighbor] = val + weight;
                    q.push({stops + 1, neighbor, dist[neighbor]});
                }
            }
        }
        return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
        
    }
};