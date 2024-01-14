class Solution {
public:
    bool closeStrings(string word1, string word2) {
//         if(word1.size()!=word2.size())
//             return false;
//         unordered_map<char, int> mpp;

//         // Count frequency of characters in string t
//         for (auto ch : word2) {
//             mpp[ch]++;
//         }

//         // Count the frequency of characters in string s and adjust the frequency map
//         for (auto ch : word1) {
//             if (mpp.find(ch) != mpp.end() && mpp[ch] > 0) {
//                 mpp[ch]--;
//             }
//         }
//      int ans = 0;

//         // Calculate the sum of remaining characters in t
//         for (auto& pair : mpp) {
//             ans += pair.second;
//         }

//         if(ans==0)
//             return true;
        
//      return false;
        
    std::unordered_map<char, int> freq1;
    std::unordered_map<char, int> freq2;

    for (auto ch : word1)
        freq1[ch]++;

    for (auto ch : word2)
        freq2[ch]++;

    std::vector<int> s1;
    std::vector<int> s2;
        vector<char> ch1;
        vector<char> ch2;

    for (auto pair : freq1) {
        s1.push_back(pair.second);
        ch1.push_back(pair.first);
    }

    for (auto pair : freq2) {
        s2.push_back(pair.second);
        ch2.push_back(pair.first);
    }

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());
        sort(ch1.begin(), ch1.end());
        sort(ch2.begin(), ch2.end());

    return s1 == s2 && ch1==ch2;
        
    }
};