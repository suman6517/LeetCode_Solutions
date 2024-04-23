class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_set<int>ans;
        for(int i = 0 ; i<nums.size(); i++)
        {
            if(ans.find(nums[i]) != ans.end())
            {
                return nums[i];
            }
            else
            {
                ans.insert(nums[i]);
            }
        }
        return -1;
    }
};