class Solution {
public:
    string reorganizeString(string s) {
      // vector<int> cnt(26);
      //   int mostfreq=0;
      //   int i=0;
      //   for(char c:s)
      //   {
      //       if(++cnt[c-'a']>cnt[mostfreq])
      //           mostfreq=(c-'a');
      //   }
   unordered_map<char, int> cnt;
char mostfreq = ' ';

for (char c : s) {
    cnt[c]++;
    if (cnt[c] > cnt[mostfreq]) {
        mostfreq = c;
    }
}

string ans(s.size(), ' ');

if (2 * cnt[mostfreq] - 1 > s.size()) return "";
int i = 0;
while (cnt[mostfreq]) {
    ans[i] = mostfreq;
    i += 2;
    cnt[mostfreq]--;
}

for (auto it = cnt.begin(); it != cnt.end(); ++it) {
    while (it->second) {
        if (i >= s.size()) {
            i = 1;
        }
        ans[i] = it->first;
        it->second--;
        i += 2;
    }
}

return ans;


    }
};
