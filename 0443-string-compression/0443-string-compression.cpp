class Solution {
public:
    // while (num > 0) {
    //     char digit = '0' + num % 10;
    //     result = digit + result;  // Append digit to result
    //     num /= 10;  // Move to next digit
    // }
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int index=0;
        while(i<n)
        {
            char curr=chars[i];
            int cnt=0;
            while(i<n && chars[i]==curr)
            {
                i++;
                cnt++;
            }
            
            chars[index]=curr;
            index++;
            if(cnt>1)
            {
                string count_str=to_string(cnt);
                for(auto &ch:count_str)
                {
                    chars[index]=ch;
                    index++;
                }
            }
        }
        return index;
    }
};