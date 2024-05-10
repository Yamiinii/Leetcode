#include <vector>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<double, pair<int, int>> mpp;
        
        // Generate all possible fractions and store them in the map
        for(int i = 0; i < arr.size() - 1; i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                double fraction = static_cast<double>(arr[i]) / arr[j];
                mpp[fraction] = {arr[i], arr[j]};
            }
        }
        
        // Traverse the map to find the kth smallest prime fraction
        int count = 0;
        for(auto& entry : mpp) {
            if(++count == k)
                return {entry.second.first, entry.second.second};
        }
        
        return {}; // If k is out of bounds or no fractions found
    }
};
