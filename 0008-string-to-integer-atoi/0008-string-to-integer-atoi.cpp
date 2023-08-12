class Solution {
public:
    int myAtoi(string s) {
       bool positive = true; // Default to positive
        int result = 0;

        int i = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            positive = (s[i] == '+');
            i++;
        }

        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for integer overflow
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return (positive) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return (positive) ? result : -result;
    }
};