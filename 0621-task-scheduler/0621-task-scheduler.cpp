class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        for(auto it:tasks)
            mpp[it]++;
      priority_queue<int> maxheap;
        for(auto it:mpp)
        {
            maxheap.push(it.second);
        }
        
        int cycles=0;
        while(!maxheap.empty())
        {
            vector<int> temp;
            for(int i=0;i<=n;i++)
            {
                if(!maxheap.empty())
                {
                    temp.push_back(maxheap.top());
                    maxheap.pop();
                }
            }
            
            for(auto count:temp)
            {
                count--;
                if(count>0)
                    maxheap.push(count);
            }
            
            if(maxheap.empty())
                cycles+=temp.size();
            else
                cycles+=n+1;
        }
        
        return cycles;
    }
};