//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
const int m=1e9+7;
  public:
    int perfectSum(int arr[], int n, int sum)
    {
        int s=sum;
        vector<vector<int>> t(n+1,vector<int>(sum+1,0));
         int cnt=1;
        t[0][0]=1;
        for(int i=0;i<n;++i)
        {
            if(arr[i]==0)
            {   cnt*=2;
                t[i+1][0]=cnt;
            }
            else
                t[i+1][0]=t[i][0];
        }
        
         
        // 2. Second Step.
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(arr[i-1]<=j) 
                    t[i][j] = (t[i-1][j] + t[i-1][j-arr[i-1]]) %m;
                else
                    t[i][j] = t[i-1][j]%m ;
            }
        }
        
     /*    for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            cout<<t[i][j]<<" ";
            cout<<endl;
            
        } */
        return t[n][s];
        
    }
      
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends