class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int front = 0;
        int back = 0;
        int len = 0;
        unordered_set<char> charSet; // Set to track characters in the current substring
        
        while (back < s.length()) {
            char c = s[back];
            
            // If the character is not in the current substring, add it to the set and move the window.
            if (charSet.find(c) == charSet.end()) {
                charSet.insert(c);
                len = max(len, back - front + 1);
                back++;
            } else {
                // If the character is already in the substring, remove the front character and move the window.
                charSet.erase(s[front]);
                front++;
            }
        }
        
        return len;
    }
};
