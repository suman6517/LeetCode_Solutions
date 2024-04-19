class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>sub;
        int size = nums.size();
        int index = 0;
        rec(ans, nums, sub , size , index);
        return ans;
    }
    void rec(vector<vector<int>>&ans ,vector<int>& nums , vector<int>&sub , int size , int index)
    {
        if (index >= size)
        {
            ans.push_back(sub);
            return ;
        }
        rec(ans, nums , sub , size , index+1);
        sub.push_back(nums[index]);
        rec(ans, nums , sub , size , index+1);
        sub.pop_back();
       
    }
};