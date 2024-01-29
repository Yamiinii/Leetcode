#include <stack>

class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;

public:
    MyQueue() {
    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (!output.empty()) {
            int front = output.top();
            output.pop();
            return front;
        } else {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            int front = output.top();
            output.pop();
            return front;
        }
    }

    int peek() {
        if (!output.empty()) {
            return output.top();
        } else {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }

    bool empty() {
        if (!output.empty()) {
            return false;
        } else {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            return output.empty();
        }
    }
};
