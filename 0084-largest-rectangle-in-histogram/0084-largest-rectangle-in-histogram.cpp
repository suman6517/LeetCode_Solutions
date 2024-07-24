class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int size = heights.size();
        stack<int>st;
        int maxArea = 0;

        for(int i=0; i<size; i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int element = st.top();
                st.pop();

                int nse = i; 
                int pse = st.empty() ? -1: st.top();

                maxArea = max((heights[element] * (nse - pse -1)),maxArea);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            int nse = size;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1: st.top();
            maxArea = max((heights[element] * (nse - pse -1)),maxArea);

        }
        return maxArea;
    }
};