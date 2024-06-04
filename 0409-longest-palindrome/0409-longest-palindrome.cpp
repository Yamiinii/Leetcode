class Solution {
public:
int longestPalindrome(string s) {
    unordered_map<char, int> mpp;
    int n = s.length();
    int number = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        mpp[s[i]]++;
    }
    int oddnum=0;
    for (auto it:mpp) {
        if (it.second % 2 != 0) {
            number+=it.second-1;
            oddnum++;
        } else {
            number+=it.second;
        }
    }
    if(oddnum>0)
        return ++number;
    return number;
}
};