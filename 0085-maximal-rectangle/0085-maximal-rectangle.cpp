#include <vector>
#include <stack>
#include <algorithm> // for std::max
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        stack<int> st1;

        // Compute left boundaries
        for (int i = 0; i < n; i++) {
            while (!st1.empty() && heights[st1.top()] >= heights[i])
                st1.pop();

            if (st1.empty())
                left[i] = 0;
            else
                left[i] = st1.top() + 1;

            st1.push(i);
        }

        // Clear the stack for reuse
        while (!st1.empty())
            st1.pop();

        vector<int> right(n);
        stack<int> st2;

        // Compute right boundaries
        for (int i = n - 1; i >= 0; i--) {
            while (!st2.empty() && heights[st2.top()] >= heights[i])
                st2.pop();

            if (st2.empty())
                right[i] = n - 1;
            else
                right[i] = st2.top() - 1;

            st2.push(i);
        }

        // Calculate maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (right[i] - left[i] + 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int maxarea = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0); // Initialize heights array for the first row

        // Iterate over each row of the matrix
        for (int i = 0; i < m; i++) {
            // Update the heights array based on the current row
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }

            // Compute the largest rectangle area in the histogram formed by 'heights'
            maxarea = max(maxarea, largestRectangleArea(heights));
        }

        return maxarea;
    }
};
