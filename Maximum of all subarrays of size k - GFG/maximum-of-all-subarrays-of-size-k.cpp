//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        int start=0;
        int end=0;
        vector<int> ans;
        list<int> l;
         if (k>n) // edge case
        {
            ans.push_back(*max_element(l.begin(),l.end()));
            return ans;
        }
        while(end<n)
        {
           while(l.size()>0 && l.back()<arr[end])
           l.pop_back();
            l.push_back(arr[end]);
           if(end-start+1<k)
           end++;
           else if(end-start+1==k)
           {
               ans.push_back(l.front());
               if(l.front()==arr[start])
               l.pop_front();
               
               start++;
               end++;
               
           }
        }
        
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends