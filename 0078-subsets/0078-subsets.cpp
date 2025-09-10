class Solution {
public:
void printSubsets(int currentIndex ,vector<vector<int>>&ans,vector<int>&temp , int size , vector<int>nums)
{
    // Base Condition
    if(currentIndex >=size)
    {
        ans.push_back(temp);
        return;
    }

    // include The number
    temp.push_back(nums[currentIndex]);
    printSubsets (currentIndex+1, ans, temp , size, nums);

    // Exclude the number
    temp.pop_back();
    printSubsets(currentIndex+1, ans, temp , size, nums);
}

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        vector<int>temp;
        int size = nums.size();
        printSubsets(0 , ans,temp,size,nums);

        return ans;
    }
};