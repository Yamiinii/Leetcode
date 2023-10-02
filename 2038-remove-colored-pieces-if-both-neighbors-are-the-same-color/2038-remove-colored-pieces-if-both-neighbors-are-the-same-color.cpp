class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int colorA=0;
        int colorB=0;
        for(int i=0;i<n;i++)
        {
            char x=colors[i];
            int count=0;
            while(i<n && colors[i]==x)
            {
                i++;
                count++;
                
            }
            if(x=='A')
            {
                colorA+=(count-2>0)?count-2:0;
            }
            else  if(x=='B')
            {
                colorB+=(count-2>0)?count-2:0;
            }
            i--;
        }
        return colorA>colorB;
    }
};