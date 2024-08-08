class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int idx=nums.size()-1;
        vector<int> ans(nums.size(),0);
        while(start<=end)
        {
            int sq_front=nums[start]*nums[start];
            int sq_back=nums[end]*nums[end];
            if(sq_front>sq_back)
            {
                ans[idx]=sq_front;
                start++;
            }
            else
            {
                ans[idx]=sq_back;
                end--;
            }
            
            idx--;
        }
        
        return ans;
    }
};