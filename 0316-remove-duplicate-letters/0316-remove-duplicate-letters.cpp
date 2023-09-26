class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Initialize an array to store the last occurrence index of each character.
        vector<int> last_occurrence(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        // Initialize a stack to build the result string.
        stack<char> st;
        // Initialize a set to keep track of characters in the stack.
        unordered_set<char> inStack;

        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];

            // If the current character is not in the stack, try to add it.
            if (inStack.find(currentChar) == inStack.end()) {
                // Remove characters from the stack if they are greater and have more occurrences later.
                while (!st.empty() && currentChar < st.top() && i < last_occurrence[st.top() - 'a']) {
                    inStack.erase(st.top());
                    st.pop();
                }

                // Add the current character to the stack and mark it as in the stack.
                st.push(currentChar);
                inStack.insert(currentChar);
            }
        }

        // Build the result string from the stack.
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};
