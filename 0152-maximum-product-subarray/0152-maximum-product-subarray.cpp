class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curr=1;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            curr=curr*nums[i]; 

            if(curr==0)
            curr=nums[i];
            
            maxi=max(maxi,curr);
        }

        curr=1;
        for(int i=n-1;i>=0;i--)
        {
            curr=curr*nums[i]; 

            if(curr==0)
            curr=nums[i];
            
            maxi=max(maxi,curr);
        }

        return maxi;
    }
};