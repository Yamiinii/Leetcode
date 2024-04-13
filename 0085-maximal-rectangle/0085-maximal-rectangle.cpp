class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> height(m, 0);
        int maxArea = 0;
        
        for (int i = 0; i < n; i++) {
            // Update the heights array based on the current row
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            
            // Calculate the maximal rectangle area with the current heights array
            maxArea = max(maxArea, maxHistogramArea(height));
        }
        
        return maxArea;
    }
    
private:
    int maxHistogramArea(const vector<int>& height) {
        stack<int> s;
        int maxArea = 0;
        int n = height.size();
        
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || height[s.top()] > height[i])) {
                int h = height[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            s.push(i);
        }
        
        return maxArea;
    }
};
