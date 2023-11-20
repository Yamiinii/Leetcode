class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        long long totalMinutes = 0;  // Total minutes needed for garbage collection
        long long currentTravelTime = 0;  // Current travel time

        // Add the initial minutes required to collect garbage at the first house
        totalMinutes += garbage[0].size();

        vector<int> lastGarbageIndices(3, -1);  // Keep track of the last occurrence of each type of garbage

        // Iterate through each house starting from the second house
        for (int houseIndex = 1; houseIndex < garbage.size(); houseIndex++) {
            // Add the minutes required to collect garbage at the current house
            totalMinutes += garbage[houseIndex].size();

            // Update the indices of the last occurrence of each type of garbage
            if (garbage[houseIndex].find("M") != garbage[houseIndex].npos) 
                lastGarbageIndices[0] = houseIndex - 1;
            if (garbage[houseIndex].find("P") != garbage[houseIndex].npos) 
                lastGarbageIndices[1] = houseIndex - 1;
            if (garbage[houseIndex].find("G") != garbage[houseIndex].npos) 
                lastGarbageIndices[2] = houseIndex - 1;
        }

        // Iterate through each travel segment
        for (int travelIndex = 0; travelIndex < travel.size(); travelIndex++) {
            // Add the current travel time
            currentTravelTime += travel[travelIndex];

            // Add the minutes required to collect garbage if a garbage truck is at the corresponding house
            for (int truckIndex = 0; truckIndex < 3; truckIndex++) {
                if (lastGarbageIndices[truckIndex] == travelIndex) {
                    totalMinutes += currentTravelTime;
                }
            }
        }

        return totalMinutes;
    }
};