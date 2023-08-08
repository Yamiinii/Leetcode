class CustomStack {
private:
    vector<int> stack;
    int maxsize;

public:
    CustomStack(int maxSize) {
        maxsize = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < maxsize)
            stack.push_back(x);
    }
    
    int pop() {
        if (stack.empty())
            return -1; // Return some value to indicate underflow
        int val = stack.back();
        stack.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < min(k, static_cast<int>(stack.size())); i++) {
            stack[i] += val;
        }
    }
};
