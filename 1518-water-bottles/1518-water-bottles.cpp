class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
         int emptyBottles = numBottles;
        while (emptyBottles >= numExchange) {
        int fullBottles = emptyBottles / numExchange;
        ans += fullBottles;
        emptyBottles = fullBottles + (emptyBottles % numExchange);
    }
    
    return ans;
    }
};