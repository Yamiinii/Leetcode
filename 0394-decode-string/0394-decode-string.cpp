class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans = ""; // Initialize ans to store the decoded string
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                st.push(s[i]); // Push characters onto stack until we encounter ']'
            } else {
                string substr = ""; // To store the substring that needs to be repeated
                
                // Pop characters from stack until we encounter '['
                while (!st.empty() && st.top() != '[') {
                    substr = st.top() + substr;
                    st.pop();
                }
                st.pop(); // Remove '[' from stack
                
                string num = ""; // To store the number that indicates repetition
                
                // Pop characters from stack until we encounter a non-digit
                while (!st.empty() && isdigit(st.top())) {
                    num = st.top() + num;
                    st.pop();
                }
                
                // Convert num from string to integer
                int repeatCount = stoi(num);
                
                // Repeat the substring 'repeatCount' times and push it back to stack
                for (int j = 0; j < repeatCount; j++) {
                    for (char ch : substr) {
                        st.push(ch);
                    }
                }
            }
        }
        
        // Build the final decoded string from the stack
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};
