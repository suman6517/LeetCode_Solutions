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
        
        //exclude
        rec(ans , nums, sub , size , index+1);

        //Include
        int element = nums[index];
        sub.push_back(element);
        rec(ans , nums, sub , size , index+1);
        sub.pop_back();
    }
};