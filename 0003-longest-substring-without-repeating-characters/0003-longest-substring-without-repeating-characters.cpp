class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int end = 0;
        unordered_map<char, int> unique_ele;
        int cnt = 0;
        int ans = 0;

        while (end < s.size()) {
            if (unique_ele.count(s[end]) == 0) {
                unique_ele[s[end]]++;
                cnt++;
                ans = max(cnt, ans);
                end++;
            } else {
                unique_ele.erase(s[start]);
                cnt--;
                start++;
            }
        }

        return ans;
    }
};
