class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        
        // Sort is not strictly necessary for the binary search algorithm but can be useful for understanding
        // the bounds. For this particular problem, it doesn't impact the binary search logic.
        sort(time.begin(), time.end()); 

        long long low = 1;
        long long high = static_cast<long long>(time.back()) * totalTrips;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long actualTrips = 0;

            // Calculate total number of trips completed by all buses in `mid` time units
            for (int t : time) {
                actualTrips += mid / t;
                if (actualTrips >= totalTrips) {
                    break; // No need to continue if we've already met the required number of trips
                }
            }

            // Adjust the search range based on the number of trips completed
            if (actualTrips < totalTrips) {
                low = mid + 1; // Increase time
            } else {
                high = mid; // Decrease time, including `mid` as a possible solution
            }
        }

        return low;
    }
};
