class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
       sort(time.begin(),time.end());
        long long low=1;
        long long high = static_cast<long long>(time.back()) * totalTrips;
        while(low<high)
        {
                  long long mid = low + (high - low) / 2;
            long long actualTrips = 0;
             for(int i=0;i<time.size();i++){
            actualTrips+=mid/time[i];
                //      if (actualTrips >= totalTrips) {
                //     break; // No need to continue if we've already met the required number of trips
                // }
                 
        }
            if(actualTrips<totalTrips)
                low=mid+1;
            else
                high=mid;
        }
        
        return low;
    }
};