class Solution {
public:
    // void binary(int low,int high,vector<int> &v,int target,vector<int> & nums)
    // {
    //      while(low<=high)
    //     {
    //         int mid=(low+(high-low))/2;
    //         if(nums[mid]==target)
    //             v.push_back(mid);
    //         else if(nums[mid]>target)
    //             binary(low,mid-1,v,target,nums);
    //         else
    //             binary(mid+1,high,v,target,nums);
    //     }
    // }
    
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> v;
       //  int low=0;
       //  int high=nums.size()-1;
       // binary(low,high,v,target,nums);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>target)
                break;
            if(nums[i]==target)
                v.push_back(i);
        }
        return v;
    }
};