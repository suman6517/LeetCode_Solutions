class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> result(size, -1); 
        stack<int>st;

        for(int i =2*size -1; i>=0; i--)
        {
            while(!st.empty() && st.top() <= nums[i%size])
            {
                st.pop();
            }
            if (!st.empty())
            {
                result[i%size] = st.top();
            }
            st.push(nums[i % size]);
        }
        return result;
    }
};