#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
   bool allstar(string p,int i){
        
        for(int it=1;it<=i;it++){
                  if(p[it-1]!='*'){
                      return false;
                }
            }
                return true;
    }
    bool isMatch(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        
        dp[0][0]=true;
        
                for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                
                if(i==0 && j==0) dp[i][j] = true;
                
                if(j==0){
                    dp[i][j] = false;
                }
                if(i==0){
                    dp[i][j] = allstar(p,j);
             }
            }
           }
        

        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                
            if(s[i-1] == p[j-1] || p[j-1] == '?') 
             dp[i][j] = dp[i-1][j-1];
    
        else{ 
            
            if(p[j-1]=='*'){
            dp[i][j] = dp[i-1][j] || dp[i][j-1];
        } 
        else 
         dp[i][j] = false;
    }
                
            }
        }
        
        return dp[n][m];
    }
};
