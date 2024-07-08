class Solution {
public:
    //Moore Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int num;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                cnt=1;
                num=nums[i];
            }
            else if(nums[i]==num)
                cnt++;
            else
                cnt--;
        }
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]==num)
               sum++;
        }
        
        if(sum>=nums.size()/2)
            return num;
        
        return -1;
    }
};