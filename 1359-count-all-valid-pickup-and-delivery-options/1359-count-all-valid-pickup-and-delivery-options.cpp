#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007; // Modulus for calculations
const int MAX_PAIRS = 510;   // Maximum possible pairs value

class Solution {
private:
    vector<long long> memoization;

    long long calculateOrdersCount(int remainingPairs) {
        // Base case: No remaining pairs, return 1
        if (remainingPairs == 0)
            return 1;

        // Check if the value is already computed and return it
        if (memoization[remainingPairs] != -1)
            return memoization[remainingPairs];

        // Calculate the number of valid orders for the remaining pairs
        long long currentResult = calculateOrdersCount(remainingPairs - 1) * (2LL * remainingPairs - 1) * remainingPairs % MOD;

        // Store the result in the memoization array and return it
        return memoization[remainingPairs] = currentResult;
    }

public:
    int countOrders(int numPairs) {
        // Initialize the memoization array with -1 values
        memoization.resize(numPairs + 1, -1);

        // Calculate and return the count of valid orders
        return static_cast<int>(calculateOrdersCount(numPairs));
    }
};