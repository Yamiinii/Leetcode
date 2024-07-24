class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize prefix and suffix arrays
        vector<int> pref(n);
        vector<int> suff(n);
        
        pref[0] = 1;
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] * nums[i - 1];
        }
        
        suff[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i + 1];
        }
        
        // Compute ans array
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = pref[i] * suff[i];
        }
        
        return ans;
    }
};
