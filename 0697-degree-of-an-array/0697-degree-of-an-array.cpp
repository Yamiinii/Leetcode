class Details{
    public:
    int freq;
    int start;
    int end;
    Details()
    {
        int freq=0;
        int start=0;
        int end=0;
        
    }
};

class Solution {

public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,Details> mpp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.count(nums[i])==0)
            {
                mpp[nums[i]].freq++;
                mpp[nums[i]].start=i;
                mpp[nums[i]].end=i;
                
            }
            else
                mpp[nums[i]].freq++;
            mpp[nums[i]].end=i;
        }
        
        int deg=INT_MIN;
        int len=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(mpp[nums[i]].freq>deg)
            {
                deg=mpp[nums[i]].freq;
                len=mpp[nums[i]].end-mpp[nums[i]].start+1;
            }
            if(mpp[nums[i]].freq==deg)
            {
                if(len>mpp[nums[i]].end-mpp[nums[i]].start+1)
                len=mpp[nums[i]].end-mpp[nums[i]].start+1;
            }
        }
        return len;
    }
};