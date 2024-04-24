class Solution {

    void solveFunc(vector<vector<int>>&ans, vector<int>nums , int index)
    {
        //Base Case
        if(index >=nums.size())
        {
            ans.push_back(nums);
            return;
        }

        // Logic
        for(int i = index ; i<nums.size(); i++)
        {
            swap(nums[index] , nums[i]);
            //Recursive Call;
            solveFunc(ans, nums, index+1);

            //Backtrack
            swap(nums[index] , nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        int index = 0;
        solveFunc(ans, nums, index);
        return ans ;
    }
};