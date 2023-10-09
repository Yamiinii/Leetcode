class Solution {
public:
    int binary(vector<int>& nums, int target,bool firstoccur)
    {
        int ans=-1;
            int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(target<nums[mid])
            {
                r=mid-1;
            }
            else if(target> nums[mid])
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                if(firstoccur)
                {
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        ans[0]=binary(nums,target,true);
        if(ans[0]!=-1)
        {
            ans[1]=binary(nums,target,false);
        }
        return ans;
    }
};