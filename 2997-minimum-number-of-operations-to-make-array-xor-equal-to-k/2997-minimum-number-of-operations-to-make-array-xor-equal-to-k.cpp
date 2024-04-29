class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
         vector<int>oneCount(32, 0);
        for (int num : nums)
        {
            for (int i = 0; i < 32; i++)
            {
                if (num & (1 << i))
                    oneCount[i]++;
            }
        }
        //=====================================================
        int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if (k & (1 << i)) //if ith bit in k = 1 (set)
            {
                if (oneCount[i] % 2 == 0) //we wanted odd number of 1's but got even number of 1's
                    ans++;
            }
            else   //if ith bit in k = 0 (unset)
            {
                if (oneCount[i] % 2 != 0) //we wanted even number of 1's but got odd number of 1's
                    ans++;
            }
        }
        //====================================================
        return ans;
    }
};