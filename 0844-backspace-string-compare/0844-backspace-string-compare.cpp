class Solution {
public:
    bool backspaceCompare(string s, string t) {
        deque<char> dq1;
        for (auto si : s) {
            if (si != '#')
                dq1.push_back(si);
            else if (!dq1.empty())
                dq1.pop_back();
        }
        
        deque<char> dq2;
        for (auto ti : t) {
            if (ti != '#')
                dq2.push_back(ti);
            else if (!dq2.empty())
                dq2.pop_back();
        }
        
        int n = dq1.size();
        int n1 = dq2.size();
        if (n != n1)
            return false;
        for (int i = 0; i < n; i++) {
            if (dq1[i] != dq2[i])
                return false;
        }
        return true;
    }
};
