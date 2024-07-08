class Solution {
public:
    //modified version of the Boyer-Moore Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int num1;
        int cnt1=0;
        int num2;
        int cnt2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 && nums[i]!=num2)
            {
                cnt1=1;
                num1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=num1)
            {
                cnt2=1;
                num2=nums[i];
            }
            else if(nums[i]==num1)
                cnt1++;
            else if(nums[i]==num2)
                cnt2++;
            else
               { cnt1--;
               cnt2--;}
        }
        
       cnt1 = 0;
        cnt2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == num1)
                cnt1++;
            else if (nums[i] == num2)
                cnt2++;
        }
        
        // Step 3: Determine which candidates appear more than n/3 times
        vector<int> result;
        if (cnt1 > nums.size() / 3)
            result.push_back(num1);
        if (cnt2 > nums.size() / 3 && num1 != num2) // Avoid duplicates
            result.push_back(num2);
        
        return result;
    }
};