class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        int n=nums.size();
        if(n<3)
        return v;
        //sorting
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>> mpp;
        int val=0;
        // for(int j=0;j<n;j++)
        // {
        //     for(int k=j+1;k<n;k++)
        //     {
        //         val=-1*(nums[k]+nums[j]);
        //         if(mpp.find(val)!=mpp.end())
        //         {
        //             for(auto i:mpp[val])
        //             {
        //                 v.push_back({i,j,k});
        //             }
        //         }
        //     }

        //     mpp[val].push_back(j);
        // }

        //will using sliding window and check for duplicates as well
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;

            int left=i+1;
            int right=n-1;

            while(left<right)
            {
                int sum=nums[i]+nums[left]+nums[right];

                if(sum==0)
                {v.push_back({nums[i],nums[left],nums[right]});
                left++;
                right--;
                
                 while(left<right && nums[left]==nums[left-1])
                left++;

                while(left<right && nums[right]==nums[right+1])
                right--;
                }

               

                else if (sum < 0) {
                    left++;
                }

            else
            right--;

            }
        }

        return v;
    }
};