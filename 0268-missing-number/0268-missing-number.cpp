class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //xor with 0 same num do that twice it is zero
        //A ^ 0 = A
// (XOR with 0 gives the original number)

// A ^ A = 0
// (XOR with itself gives 0)

// A ^ B = C ⇒ C ^ B = A
// (XOR is reversible: you can get back the original number if you know one operand)
        int result=0;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            result^=i;
        }
        for(int i=0;i<n;i++)
        {
            result^=nums[i];
        }
        return result;
    }
};