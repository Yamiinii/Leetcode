class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums) {
        original=nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> saving=original;
        int leftsize=saving.size();
        int n=saving.size();
        for(int i=n-1;i>=0;i--)
        {
            int j=rand()%leftsize;
            swap(saving[i],saving[j]);
            leftsize--;
        }
        return saving;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */