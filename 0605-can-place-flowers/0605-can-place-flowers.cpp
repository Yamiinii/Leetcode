class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() == 1)
        {
            if(flowerbed[0] == 0 && n == 1)
            {
                return true;
            }
            else if((flowerbed[0] == 1 || flowerbed[0] == 0) && n == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        int count = 0;
        int prev = flowerbed[0];
        for(int i = 1 ; i < flowerbed.size();i++)
        {
          if(flowerbed[0] == 0 && flowerbed[1] == 0)
          {
              flowerbed[0] = 1;
              count++; 
          }
          else if(flowerbed[i] == 0 && prev == 0)
          {
            count++;
            flowerbed[i] = 1;
            
          }
          else if(prev == 1 && flowerbed[i] == 1)
          {
            count--;
          }
          prev = flowerbed[i];
        }
        
        return count>n-1;
    }
};