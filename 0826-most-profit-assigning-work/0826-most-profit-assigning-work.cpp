class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int sum=0;
        for(int i=0;i<worker.size();i++)
        {
            int maxi=0;
            for(int j=0;j<difficulty.size();j++)
            {
                if(difficulty[j]<=worker[i])
                {
                    
                    maxi=max(maxi,profit[j]);
                }
            }
            sum+=maxi;
        }
        return sum;
    }
};