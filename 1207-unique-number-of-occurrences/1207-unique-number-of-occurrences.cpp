class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i=0;i<arr.size();i++)
        {
            
            mpp[arr[i]]++;
        }
        vector<int> v;
        for (auto& entry : mpp) {
            v.push_back(entry.second);
        }
        int n=v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++)
        {
            if(v[i]==v[i+1])
                return false;
        }
        return true;
    }
};