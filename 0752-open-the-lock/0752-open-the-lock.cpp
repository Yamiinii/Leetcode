#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;
        if (target == "0000") return 0;
        
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited{"0000"};
        int level = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string current = q.front();
                q.pop();
                if (current == target) return level;
                for (int j = 0; j < 4; ++j) {
                    for (int k = -1; k <= 1; k += 2) {
                        string next = current;
                        next[j] = (next[j] - '0' + k + 10) % 10 + '0';
                        if (!dead.count(next) && !visited.count(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            ++level;
        }
        
        return -1;
    }
};
