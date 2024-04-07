class Solution {
public:
    bool checkValidString(string s) {
       std::stack<int> leftStack;
        std::stack<int> starStack;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                leftStack.push(i);
            else if (s[i] == '*')
                starStack.push(i);
            else {
                if (!leftStack.empty())
                    leftStack.pop();
                else if (!starStack.empty())
                    starStack.pop();
                else
                    return false;
            }
        }

        while (!leftStack.empty() && !starStack.empty()) {
            if (leftStack.top() > starStack.top())
                return false;
            leftStack.pop();
            starStack.pop();
        }

        return leftStack.empty();
    }
};