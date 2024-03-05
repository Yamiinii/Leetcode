class Solution {
public:
    int minimumLength(string s) {
        int front = 0;
        int back = s.length() - 1; // Correct initialization
        
        while (front < back && s[front] == s[back]) {
            char ch=s[front];
            while (front <= back && s[front] ==ch)
                front++;
            while (front <= back && s[back] == ch)
                back--;
            
        }
        
        return (back - front) + 1;
    }
};