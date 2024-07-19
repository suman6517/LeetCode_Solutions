class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>result(nums1.size() , -1);
        map<int , int>m;
        stack<int>st;
        int n = nums2.size()-1;
        for(int i=n ; i>=0; i--)
        {
            while(!st.empty() && nums2[i] > st.top())
            {
                st.pop();
            }
            
            if(!st.empty())
            {
                m[nums2[i]] = st.top();

            }
            
            else
            {
                m[nums2[i]] = -1;
            }
            st.push(nums2[i]);
        }
       for(int i =0 ; i<nums1.size() ; i++)
       {
        result[i] = m[nums1[i]];
       }
       return result;
    }
};