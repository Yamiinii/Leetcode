class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        int maxi=0;

        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }

        for(int j=0;j<maxi;j++){
            vector<int>temp;

            for(auto& i:mp){
                if(i.second>0) {
                    temp.push_back(i.first);
                    i.second--;
                }
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};