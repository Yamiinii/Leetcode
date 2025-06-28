class Solution {
public:
    unordered_map<long long, int> memo;

    long long hashKey(int i, int j) {
        return ((long long)i << 32) | j;
    }

    bool check(string &s, string &p, int i, int j) {
        int n = s.size(), m = p.size();
        if (i == n && j == m) return true;
        if (j == m) return false;

        long long key = hashKey(i, j);
        if (memo.count(key)) return memo[key];

        if (i == n) {
            for (int k = j; k < m; k++) {
                if (p[k] != '*') return memo[key] = 0;
            }
            return memo[key] = 1;
        }

        if (p[j] == '*') {
            return memo[key] = check(s, p, i + 1, j) || check(s, p, i, j + 1);
        }

        if (s[i] == p[j] || p[j] == '?') {
            return memo[key] = check(s, p, i + 1, j + 1);
        }

        return memo[key] = 0;
    }

    bool isMatch(string s, string p) {
        return check(s, p, 0, 0);
    }
};
