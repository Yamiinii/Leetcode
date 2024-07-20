class Solution {
public:
 static bool compare(const int& a, const int& b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        return s1 + s2 > s2 + s1;
    }
    
    string largestNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        
        // Concatenate the sorted integers into result string
        string ans;
        for (auto num : arr) {
            ans += to_string(num);
        }
        
        // Handle case where all numbers are zeros
        if (ans[0] == '0') {
            return "0";
        }
        
        return ans;
    }
};