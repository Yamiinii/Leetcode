class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;
        int ans = 0;
        set<char> st = {'a', 'e', 'i', 'o', 'u'};
        
        // Calculate vowel count in the first window of length k
        for (int i = 0; i < k; i++) {
            if (st.find(s[i]) != st.end()) { // Check if s[i] is a vowel
                cnt++;
            }
        }
        
        ans = cnt; // Initialize ans with the vowel count of the first window
        
        // Slide the window and update max vowel count
        for (int i = 1; i <= n - k; i++) {
            // Update cnt based on the characters going out and coming into the window
            if (st.find(s[i - 1]) != st.end()) { // Check if character going out is a vowel
                cnt--;
            }
            if (st.find(s[i + k - 1]) != st.end()) { // Check if character coming in is a vowel
                cnt++;
            }
            
            ans = max(ans, cnt); // Update ans with the maximum vowel count found
        }
        
        return ans;
    }
};
