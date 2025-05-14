class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //shifting result to left to make some space and taking & to get the last bit | op will help to combine results and then we ll keep on shifting
        uint32_t result=0;
        for(int i=0;i<32;i++)
        {
            result=((result<<1) | (n&1));
            n>>=1;
        }

        return result;
    }
};