class Solution {
public:
    bool isPalindrome(int x) {
         string stri = to_string(x);

        for(int i=0;i<stri.size()/2;i++)
        {
            if(stri[i]!=stri[stri.size()-1-i])
            return false;


        }
        return true;

    }
};