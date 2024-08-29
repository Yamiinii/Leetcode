class Solution {
public:
    long long minimumTime(vector<int>& time, int tot) {
        int n=time.size();
        sort(time.begin(),time.end());
        long long low=1;
        long long high=static_cast<long long>(time.back())*tot;
        while(low<high)
        {
            long long mid=low+(high-low)/2;
            long long actualtrips=0;
            for(int i=0;i<n;i++)
            {
                actualtrips+=mid/time[i];
            }
            
            if(actualtrips<tot)
                low=mid+1;
            else
                high=mid;
        }
        
        return low;
    }
};