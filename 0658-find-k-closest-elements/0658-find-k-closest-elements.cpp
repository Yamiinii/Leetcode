class Solution {
public:
    bool static cmp(pair<int,int> &a ,pair<int,int> &b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        
        else
            return a.first<b.first;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> v;
        vector<int> ans;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({abs(arr[i]-x),i});
        }
        sort(v.begin(),v.end(),cmp);
        for(auto i:v)
        {
            if(k)
                ans.push_back(arr[i.second]),k--;
            else
                break;
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};