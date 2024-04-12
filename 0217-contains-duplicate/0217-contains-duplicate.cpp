class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin() , nums.end());

        int size = nums.size()-1;
        int start = 0;

        while(start <size)
        {
            if (nums[start] == nums[start+1])
            {
                return true;
            }
            else
            {
                start++;
            }
        }
        return false;
    }
};