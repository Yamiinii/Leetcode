class Solution
{
public:
    bool isSafe(int u, int f, vector<int> &flower, vector<vector<int>> &graph)
    {
        for (auto v : graph[u])
            if (flower[v] == f)
                return false;
        return true;
    }
    bool solve(int u, int n, vector<int> &flower, vector<vector<int>> &graph)
    {
        if (u == n + 1)
            return true;
        for (int f = 1; f <= 4; f++)
        {
            if (isSafe(u, f, flower, graph))
            {
                flower[u] = f;
                if (solve(u + 1, n, flower, graph) == true)
                    return true;
                flower[u] = 0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<vector<int>> graph(n + 1);
        for (auto e : paths)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> flower(n + 1, 0);
        solve(1, n, flower, graph);
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            ans.push_back(flower[i]);
        return ans;
    }
};