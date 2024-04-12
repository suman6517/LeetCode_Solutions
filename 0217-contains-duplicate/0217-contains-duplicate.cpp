class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int , int > m;

        for (auto n : nums)
        {
            m[n] ++ ;
        }
        for (auto result : m)
        {
            if (result.second >1)
            {
                return true;
            }
        }
        return false;
    }
};