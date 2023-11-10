#include <vector>
#include <unordered_map>

class Solution {
public:
    void dfs(std::unordered_map<int, std::vector<int>>& adjList, set<int>& visited, std::vector<int>& v, int node) {
       if(visited.find(node)!=visited.end())
           return;
        v.push_back(node);
        visited.insert(node);
       for(auto i:adjList[node])
           dfs(adjList,visited,v,i);
        
    }

    std::vector<int> restoreArray(std::vector<std::vector<int>>& adjacentPairs) {
        std::unordered_map<int, std::vector<int>> adjList;
    for(auto arr:adjacentPairs){
            adjList[arr[0]].push_back(arr[1]);
            adjList[arr[1]].push_back(arr[0]);
        }

        int startNode = 0;
        for (const auto& i : adjList) {
            if (i.second.size() == 1) {
                startNode = i.first;
                break;
            }
        }

        std::vector<int> v;
        set<int> visited;
        dfs(adjList, visited, v, startNode); // Start DFS from any node in the graph
        return v;
    }
};
