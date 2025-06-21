class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> v;
        for(auto s:strs)
        {
            string key=s;
            sort(key.begin(),key.end());
            v[key].push_back(s);
        }
        vector<vector<string>> ans;
        // for(int i=0;i<v.size();i++)
        // {
        //     ans.push_back(v[i].second);
        // }
        //unordered_map does not support indexing
        for(auto& pair : v) {
            ans.push_back(pair.second);
        }

        return ans;
    }


};