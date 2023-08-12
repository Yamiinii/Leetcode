class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> mpp;
        int cnt = 0;
        
        // Populate the frequency map for characters in 'chars'
        for (int i = 0; i < chars.size(); i++) {
            mpp[chars[i]]++;
        }
        
        // Iterate through each word in 'words'
        for (int i = 0; i < words.size(); i++) {
            unordered_map<char, int> hash = mpp; // Make a copy of the frequency map
            
            string temp = words[i];
            bool canMake = true;
            
            for (int j = 0; j < temp.length(); j++) {
                if (hash[temp[j]] <= 0) {
                    canMake = false;
                    break;
                }
                hash[temp[j]]--;
            }
            
            if (canMake) {
                cnt += temp.length();
            }
        }
        
        return cnt;
    }
};
