class Solution {
public:
    unordered_map<string, bool> memo;

    bool check(string &s, string &p, int sstart, int pstart) {
        string key = to_string(sstart) + "," + to_string(pstart);
        if (memo.count(key)) return memo[key];

        int n = s.size();
        int m = p.size();

        if (pstart == m) return memo[key] = (sstart == n);

        bool firstMatch = (sstart < n &&
                          (s[sstart] == p[pstart] || p[pstart] == '.'));

        if (pstart + 1 < m && p[pstart + 1] == '*') {
            // 1. Skip "x*" pair
            // 2. Use one "x" if it matches, and keep pattern at same spot
            return memo[key] = check(s, p, sstart, pstart + 2) ||
                               (firstMatch && check(s, p, sstart + 1, pstart));
        } else {
            return memo[key] = (firstMatch && check(s, p, sstart + 1, pstart + 1));
        }
    }

    bool isMatch(string s, string p) {
        return check(s, p, 0, 0);
    }
};
