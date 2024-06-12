class Solution {
public:
    void sortColors(vector<int>& nums) {
     int n=nums.size();   
     int start=0;
     int mid=0;
     int end=n-1; 
    while(mid<=end)
    {
        if(nums[mid]==0)
        {
            swap(nums[mid],nums[start]);
            start++;
            mid++;
        }
        else if(nums[mid]==1)
        {
             mid++;
        }
        else
        {
            swap(nums[mid],nums[end]);
            end--;
        }
    }



// int zero = 0;
// int one = 0;
// int two = 0;

// for (int i = 0; i < n; i++) {
//     if (nums[i] == 0)
//         zero++;
//     else if (nums[i] == 1)
//         one++;
//     else
//         two++;
// }

// for (int i = 0; i < zero; i++) {
//     nums[i] = 0;
// }

// for (int i = zero; i < zero + one; i++) {
//     nums[i] = 1;
// }

// for (int i = zero + one; i < zero + one + two; i++) {
//     nums[i] = 2;
// }

    }
};