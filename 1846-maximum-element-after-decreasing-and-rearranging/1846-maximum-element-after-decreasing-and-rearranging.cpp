class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
            return 1;
        sort(arr.begin(),arr.end());
        if(arr[0]!=1)
            arr[0]=1;
    
            
        for(int i=0;i<n-1;i++)
        {
            if(abs(arr[i]-arr[i+1])<=1)
                continue;
            else
            {
                arr[i+1]=arr[i]+1;
            }
        }
        
        return arr[n-1];
    }
};