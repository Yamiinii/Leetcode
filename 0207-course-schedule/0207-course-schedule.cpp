#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Initialize adjacency list and indegree vector
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build the graph and fill indegree
        for (const auto& prereq : prerequisites) {
            int u = prereq[1];
            int v = prereq[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        // Initialize the queue with nodes having 0 indegree
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Perform topological sort
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // If the number of nodes in topo is equal to numCourses, it's possible to finish all courses
        return topo.size() == numCourses;
    }
};
