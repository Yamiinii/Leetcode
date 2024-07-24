class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0 && n == 1) {
                return true;
            } else if ((flowerbed[0] == 1 || flowerbed[0] == 0) && n == 0) {
                return true;
            } else {
                return false;
            }
        }
        if(n==0)
            return true;
        
        for (int i = 0; i < flowerbed.size(); i++) {
            bool left = i == 0 || flowerbed[i - 1] == 0;
            bool right = i == flowerbed.size() - 1 || flowerbed[i + 1] == 0;
            
            if (left && right && flowerbed[i] == 0) {
                flowerbed[i] = 1; // Place a flower
                n--; // Decrease the count of flowers to be placed
                
                if (n == 0)
                    return true; // If we've placed enough flowers, return true
            }
        }
        
        return n == 0; // Return true if we've placed enough flowers, otherwise false
    }
};
