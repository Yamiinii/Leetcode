#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<string,vector<string>> mpp;
    vector<vector<string>> ans;
    unordered_set<string> seen;

    void dfs(string s, vector<string>& account) {
        seen.insert(s);
        account.push_back(s);
        for (auto it : mpp[s]) {
            if (!seen.count(it)) {
                dfs(it, account);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Build the graph
        for (auto& acc : accounts) {
            for (int i = 2; i < acc.size(); i++) {
                mpp[acc[i]].push_back(acc[i - 1]);
                mpp[acc[i - 1]].push_back(acc[i]);
            }
        }

        // DFS to merge accounts
        for (auto& acc : accounts) {
            if (!seen.count(acc[1])) {
                vector<string> account;
                account.push_back(acc[0]);
                dfs(acc[1], account);
                sort(account.begin() + 1, account.end());
                ans.push_back(account);
            }
        }

        return ans;
    }
};
