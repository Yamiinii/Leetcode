class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st1;

        for (int i = 0; i < n; i++) {
            while (!st1.empty() && arr[st1.top()] >= arr[i])
                st1.pop();

            if (st1.empty())
                left[i] = 0;
            else
                left[i] = st1.top() + 1;

            st1.push(i);
        }

        while (!st1.empty())
            st1.pop();

        vector<int> right(n);
        stack<int> st2;

        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && arr[st2.top()] >= arr[i])
                st2.pop();

            if (st2.empty())
                right[i] = n - 1;
            else
                right[i] = st2.top() - 1;

            st2.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = arr[i] * (right[i] - left[i] + 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
