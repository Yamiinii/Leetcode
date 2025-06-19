class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if (n == 0) return 0;
        int maxi=0;
        int left=0;
        int right=n-1;
        while(left<right)
        {
            int h=min(height[left],height[right]);
            int width=right-left;
            maxi=max(maxi,h*width);

            if(height[left]<height[right])
            left++;
            else
            right--;
        }

        return maxi;
    }
};