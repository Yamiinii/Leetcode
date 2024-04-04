#include <string>
#include <stack>
#include <cctype> // Include the header file for isdigit function

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')') {
                maxi = std::max(maxi, static_cast<int>(st.size())); 
                st.pop();
                
            } 
        }
        return maxi;
    }
};
