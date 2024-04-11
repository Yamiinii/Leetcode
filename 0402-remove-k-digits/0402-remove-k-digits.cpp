class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> dq;
        
        for (int i = 0; i < num.size(); i++) {
            char current = num[i];
            while (!dq.empty() && k > 0 && dq.back() > current) {
                dq.pop_back();
                k--;
            }
            dq.push_back(current);
        }
        
        // If k is still greater than 0, remove the last k characters
        while (k > 0) {
            dq.pop_back();
            k--;
        }
        
        // Convert deque to string and remove leading zeroes
        string ans = "";
        for (char c : dq) {
            if (ans.empty() && c == '0') {
                // Skip leading zeros
                continue;
            }
            ans += c;
        }
        
        // If the result is an empty string, return "0"
        if (ans.empty()) {
            return "0";
        }
        
        return ans;
    }
};
