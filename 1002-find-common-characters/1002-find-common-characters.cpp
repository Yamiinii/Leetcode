class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<char> v;
        for(auto& i : words[0]) {
            v.push_back(i);
        }
    for(auto it:words)
    {
        int k=0;
        while(k<v.size())
        {
            int check=0;
            for(int i=0;i<it.size();i++)
            {
                if(it[i]==v[k])
                {
                    it.erase(it.begin()+i);
                    check=1;
                    break;
                }
             }
            if(check==0)
                v.erase(v.begin()+k);
            else
            {
                k++;
                check=0;
            }
            
        }
    }

        vector<string> ans;
       for (auto i : v) {
            ans.push_back(string(1, i));
        }
        return ans;
    }
};
