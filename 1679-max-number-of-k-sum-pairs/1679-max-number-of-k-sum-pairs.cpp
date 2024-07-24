class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      int n = nums.size();
        int s =0;
        int e = n-1;
        sort(nums.begin(),nums.end());
        int count =0;
        while(s<e){
            if(nums[s]+nums[e] == k){
                count++;
                s++;
                e--;
            }

            else if(nums[s]+nums[e] > k){
                e--;
            }
            
            else{
                s++;
            }
        }
        return count;
    }
};