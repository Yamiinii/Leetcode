class Solution {
public:
    double bfs(const string& s, const string& d, 
               const unordered_map<string, vector<pair<string, double>>>& mpp, 
               unordered_map<string, bool>& vis) {
        if (s == d) return 1.0; // Special case where source is the destination
        
        queue<pair<string, double>> q;
        q.push({s, 1.0});
        vis[s] = true; // Mark start node as visited

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            string node = front.first;
            double value = front.second;

            if (node == d) {
                return value;
            }

            for (const auto& neighbor : mpp.at(node)) {
                if (vis.find(neighbor.first) == vis.end()) {
                    vis[neighbor.first] = true;
                    q.push({neighbor.first, value * neighbor.second});
                }
            }
        }

        return -1.0; // If no path was found
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mpp;
        int n = equations.size();
        
        for (int i = 0; i < n; ++i) {
            const string& u = equations[i][0];
            const string& v = equations[i][1];
            double value = values[i];
            mpp[u].push_back({v, value});
            mpp[v].push_back({u, 1.0 / value});
        }
        
        vector<double> ans;
        
        for (const auto& query : queries) {
            const string& start = query[0];
            const string& end = query[1];
            
            unordered_map<string, bool> vis;
            
            if (mpp.find(start) == mpp.end() || mpp.find(end) == mpp.end()) {
                ans.push_back(-1.0);
            } else {
                ans.push_back(bfs(start, end, mpp, vis));
            }
        }
        
        return ans;
    }
};
