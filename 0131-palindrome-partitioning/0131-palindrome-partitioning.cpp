#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool ispalindrome(string temp) {
        int i = 0;
        int j = temp.size() - 1;
        while (i <= j) {
            if (temp[i] != temp[j])
                return false;
            i++; // Increment i
            j--; // Decrement j
        }
        return true;
    }
    
    void solve(vector<vector<string>>& ans, vector<string>& str, string s) {
        if (s.empty()) {
            ans.push_back(str);
            return;
        }
        
        for (int i = 0; i < s.size(); i++) { // Corrected loop condition
            string temp = s.substr(0, i + 1);
            if (ispalindrome(temp)) {
                str.push_back(temp);
                solve(ans, str, s.substr(i + 1));
                str.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> str;
        solve(ans, str, s);
        return ans;
    }
};
