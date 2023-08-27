class Solution {
public:
    int dp[2001][2001];
    bool find(vector<int> &stones, int i, int k){
      if(i==stones.size()-1)
          return true;

      if(i>=stones.size()) 
          return false;

      if(dp[i][k]!=-1) 
          return dp[i][k]; 

      bool res = false;
      for(int j=-1;j<=1;j++){
          int next_jump=k+j;
          if(next_jump>0){
                int in= lower_bound(stones.begin(),stones.end(),stones[i]+next_jump)-stones.begin();
                if(in == stones.size() || stones[in]!=stones[i]+next_jump) 
                  continue;

                res=res||find(stones,in,next_jump);
          }
      }

      return dp[i][k]=res;

  }
  
  bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return find(stones, 0, 0);
  }
};