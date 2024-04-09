class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int loops=0;
        while(true)
        {     
            
            for(int i=0;i<tickets.size();i++)
            {
               if(tickets[i]==0)
                   continue;
                tickets[i]--;
                loops++;
                if(tickets[k]==0)
                    return loops;
             
            }
            
        }
        return loops;
    }
};