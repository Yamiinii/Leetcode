class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dir;
        int n = senate.length();
        for (int i = 0; i < n; i++){
            if (senate[i] == 'R'){
                rad.push(i);
            }
            else {
                dir.push(i);
            }
        }
        while (!rad.empty() && !dir.empty()){
            // Only "winner" stays in their queue
            if (rad.front() < dir.front()){
                rad.push(n++);
            }
            else {
                dir.push(n++);
            }
            rad.pop(), dir.pop();
        }
        return (rad.empty()) ? ("Dire") : ("Radiant");
    }
};