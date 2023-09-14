class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> itinerary;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph from the given tickets
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        // Start DFS from the "JFK" airport
        dfs("JFK");

        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }

    void dfs(const string& airport) {
        auto& destinations = graph[airport];
        while (!destinations.empty()) {
            string nextAirport = destinations.top();
            destinations.pop();
            dfs(nextAirport);
        }

        itinerary.push_back(airport);
    }
};
