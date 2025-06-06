class Solution {
public:
    int histogram(vector<int> & heights)
    {
        int n=heights.size();
        vector<int> left(n);
        vector<int> right(n);
        int maxi=0;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();

            if(st.empty())
            left[i]=0;
            else
            left[i]=st.top()+1;

            st.push(i);
        }
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();

            if(st.empty())
            right[i]=n-1;
            else
            right[i]=st.top()-1;

            st.push(i);
        }

        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,heights[i]*(right[i]-left[i]+1));
        }

        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
        return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<int> heights(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                heights[j]+=1;
                else
                heights[j]=0;
            }

            maxi=max(maxi,histogram(heights));
        }

        return maxi;
    }
};