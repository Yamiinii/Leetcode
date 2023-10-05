class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int tail=0;
        int ans=0;
        int head;
        for(head=0;head<nums.size();head++)
        {
            if(nums[head]!=1)
                tail=head+1;
            ans=max(ans,head-tail+1);
            
        }
        return ans;
    }
};