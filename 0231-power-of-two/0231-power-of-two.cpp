class Solution {
public:
    bool f(int n)
    {
        if(n==1)
            return true;
        if(n%2!=0)
            return false;
        return f(n/2);
    }
    
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        return f(n);
    }
};