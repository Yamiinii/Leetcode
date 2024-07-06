class Solution {
public:
    int passThePillow(int n, int time) {
        int num = n-1;
        // int i=0;
        // while(time)
        // {
        //     if()
        // }
        int q = time/num;
        int r = time%num;
        if(q%2==0) return r+1;
        else{
            return n-r;
        }
        return 0;
    }
};