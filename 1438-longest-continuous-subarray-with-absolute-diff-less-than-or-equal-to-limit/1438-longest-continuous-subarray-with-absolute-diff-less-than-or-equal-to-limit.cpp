class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> inc;
        deque<int> dec;
        int left=0;
        int maxlen=0;
        
        for(int right=0;right<nums.size();right++)
        {
            int num=nums[right];
            while(!inc.empty() && inc.back()>num)
                inc.pop_back();
            inc.push_back(num);
            
            while(!dec.empty() && dec.back()<num)
                dec.pop_back();
            dec.push_back(num);
            
            if(dec.front()-inc.front()>limit)
            {
                if(dec.front()==nums[left])
                    dec.pop_front();
                if(inc.front()==nums[left])
                    inc.pop_front();
                left++;
            }
            
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};