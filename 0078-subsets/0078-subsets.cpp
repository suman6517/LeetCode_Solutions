class Solution {
public:
 void getSubsets(vector<vector<int>>& ans, int ind, vector<int>& nums, vector<int> output)
 {
    if (ind >= nums.size())
        {
            ans.push_back(output);
            return ;
        }
    //elclude
    getSubsets(ans , ind+1 , nums , output);

    //include
    int element =  nums[ind];
    output.push_back(element);
    getSubsets(ans , ind+1 , nums , output);


 }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        int ind = 0;
        vector<int>output;

        getSubsets(ans, ind, nums, output);
        return ans ;
    }
};