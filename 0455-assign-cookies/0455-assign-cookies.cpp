class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int childIndex = 0 , cookieIndex = 0;
        int m = g.size() , n = s.size();
        while(childIndex < m && cookieIndex < n)
        {
            if(g[childIndex] <= s[cookieIndex])
            {
               childIndex ++;
            }
            cookieIndex++;
        }
        return childIndex;
    }
};