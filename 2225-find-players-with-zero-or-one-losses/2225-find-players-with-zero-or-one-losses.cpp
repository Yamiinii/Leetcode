class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        std::map<int, int> mpp;
        std::set<int> s;

        for (int i = 0; i < matches.size(); i++) {
            mpp[matches[i][1]]++;
            s.insert(matches[i][0]);
        }

        std::vector<std::vector<int>> ans(2);

        for (auto it = s.begin(); it != s.end(); ++it) {
            if (mpp.find(*it) == mpp.end()) {
                ans[0].push_back(*it);
            }
         
        }

        
    for (auto it = mpp.begin(); it != mpp.end(); ++it) {
    if (it->second == 1) {
        ans[1].push_back(it->first);
    }
}


        return ans;


    }
};