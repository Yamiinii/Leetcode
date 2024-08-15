class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;  // Min-heap based on lexicographical order
            }
            // Otherwise, compare based on frequency
            return a.first < b.first; 
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        for(auto it:words)
        {
            mpp[it]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }
        vector<string> ans;
          while (k-- > 0 && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};