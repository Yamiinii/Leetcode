class Solution {
public:
    int countHomogenous(string s) {
    long long ans = 0, count = 1, m = 1e9 + 7;
    for(int i = 1; i < s.size(); ++i){
        if(s[i] != s[i-1]){
            ans = (ans + ((count *(count + 1))%m )/2)%m;
            count = 0;
        }
        count++;
    }
    return (ans + ((count *(count + 1))%m )/2)%m;
}
};