class Solution {
public:
    void generate(vector<string> &ans, string s, int openCount, int closeCount, int n) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        
        if (openCount < n) {
            generate(ans, s + "(", openCount + 1, closeCount, n);
        }
        
        if (closeCount < openCount) {
            generate(ans, s + ")", openCount, closeCount + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        if (n > 0) {
            generate(ans, "(", 1, 0, n);
        }
        
        return ans;
    }
};
