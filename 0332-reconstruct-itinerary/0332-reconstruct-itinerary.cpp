class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> itinerary;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph from the given tickets
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        // Reverse the itinerary to obtain the correct order
        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }

    void dfs(const string& airport) {
        // Continue to explore destinations while there are more options
        while (!graph[airport].empty()) {
            string nextAirport = graph[airport].top();
            graph[airport].pop();
            dfs(nextAirport);
        }

        // Add the current airport to the itinerary when no more destinations are available
        itinerary.push_back(airport);
    }
};
