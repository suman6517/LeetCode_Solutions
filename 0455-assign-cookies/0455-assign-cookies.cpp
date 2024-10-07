class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
         sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int childIndex = 0;  // Index for children
        int cookieIndex = 0; // Index for cookies
        int m = g.size();    // Number of children
        int n = s.size();    // Number of cookies
        
        // Try to satisfy each child greed factor with a cookie
        while (childIndex < m && cookieIndex < n)
        {
            // If current cookie can satisfy the current child's greed
            if (s[cookieIndex] >= g[childIndex]) 
            {
                childIndex++;  // Move to the next child
            }
            // Move to the next cookie
            cookieIndex++;
        }
        
        // The number of children that are satisfied
        return childIndex;
    }
};