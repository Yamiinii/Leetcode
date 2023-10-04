class Solution {
   vector<vector<int>>v;
public:
    int solve(int k, int n) {
        if(k==1)
return n;
if(n==0 || n==1)
return n;
if(v[k][n]!=-1)
return v[k][n];
int mini=INT_MAX;
int l=1,h=n,temp=0;
 while(l<=h)
    {
        int mid=(l+h)/2;
        int left=solve(k-1,mid-1);  
        int right=solve(k,n-mid) ;   
        temp=1+max(left,right);          
        if(left<right){                 
          l=mid+1;                       
        }
        else                            
        {    
            h=mid-1;
        }
    mini=min(mini,temp);             
    }
    
    return  v[k][n]=mini;
    }
    
    int superEggDrop(int k, int n) {
      v.resize(k + 1,vector<int>(n+1,-1));
   return solve(k,n);
    }
};
