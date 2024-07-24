class Solution {
public:
    int gcd(int a, int b) 
{ 
    // Find Minimum of a and b 
    int result = min(a, b); 
    while (result > 0) { 
        if (a % result == 0 && b % result == 0) { 
            break; 
        } 
        result--; 
    } 
  
    // Return gcd of a and b 
    return result; 
}
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1)?str1.substr(0, gcd(size(str1),size(str2))): ""; 
    }
};