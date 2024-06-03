class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;

        // Traverse through s and t to find the length of the longest subsequence of t in s
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                j++;
            }
            i++;
        }
        
        // The number of characters to be appended is the length of t minus the longest subsequence found
        return m - j;
    }
};
