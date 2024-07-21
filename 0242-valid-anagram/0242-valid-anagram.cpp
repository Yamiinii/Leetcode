class Solution {
public:
    bool isAnagram(string s, string t) {
                sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Compare sorted strings
        return s == t;
//can do better but will use hash map
    }
};