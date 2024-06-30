#include <iostream>
#include <vector>

using namespace std;
//optimal using kadane
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int max_so_far=0;
        for(int i=0;i<nums.size();i++)
        {
            
            max_so_far=max_so_far+nums[i];
            if(max_so_far>maxi)
                maxi=max_so_far;
            if(max_so_far<0)
                max_so_far=0;
        }
        return maxi;
    }
};


