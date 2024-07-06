class Solution {
public:
    int isPalindrome(string s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
//     int solve(string s,int i,int j)
//     {
//         if(i>j)
//             return 0;
//         if(isPalindrome(s,i,j))
//             return 0;
//         int mini=INT_MAX;
//         for(int k=i;k<j;k++)
//         {
//             int temp=solve(s,i,k)+solve(s,k+1,j)+1;
//             int mini=min(temp,mini);
//         }
//         return mini;
//     }
void partitionHelper(string s, int start, vector<string>& current, vector<vector<string>>& result) {
    if (start == s.size()) {
        result.push_back(current);
        return;
    }
    
    for (int end = start; end < s.size(); end++) {
        if (isPalindrome(s, start, end)) {
            current.push_back(s.substr(start, end - start + 1));
            partitionHelper(s, end + 1, current, result);
            current.pop_back();
        }
    }
}

    
    vector<vector<string>> partition(string s) {
        // int n=s.size();
        // return solve(s,1,n-1);
        int n=s.size();
        vector<vector<string>> ans;
        vector<string> current;
        partitionHelper(s,0,current,ans);
        return ans;
    }
};