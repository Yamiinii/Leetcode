class Solution {
public:
    //  ***********************KADANE********************************
    //Ques : Why do we have a need to traverse from right to left ??
// Ans : lets take an example
// arr {-8,5,3,1,6}

// // By traversing left to right we have an answer maxi1.
// maxi1 = -720 , which is clearly not the max prod value.
    
    
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int product=1;
        for(int i=0;i<nums.size();i++)
        {
            product*=nums[i];
            maxi=max(product,maxi);
            if(product==0)
                product=1;
        }
        
        product=1;
          for(int i=nums.size()-1;i>=0;i--)
        {
            product*=nums[i];
            maxi=max(product,maxi);
            if(product==0)
                product=1;
        }
        
        return maxi;
    }
};