class Solution {
public:
    int myAtoi(string s) {
        //check for white space
        //check for sign
        //skip all zeroes
        //stop if a non digit is encountered
        //check if the numbers are in range
        int n=s.size();
        int i=0;
        // don't forget i<n
        while(i<n && s[i]==' ')
        i++;
        bool positive=true;
        if(s[i]=='+' || s[i]=='-')
        {
            positive=(s[i]=='+');
            i++;
        }
        while(i < n && s[i] == '0')
             i++;

        //using long long for overflow check
        long long num=0;
        while(i<n && isdigit(s[i]))
        {
            int digit=s[i]-'0';
            num=num*10+digit;

            if(positive && num>INT_MAX)
            return INT_MAX;

            if(!positive && -num<INT_MIN)
            {
                return INT_MIN;
            }
            i++;
        }

        return positive?num:-num;
    }
};