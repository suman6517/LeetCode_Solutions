class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() <=2)
        {
            return nums.size();
        }
        int length = 2;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[length - 2])
            {
                nums[length++] = nums[i];
            }
        }
        return length;

    }
};