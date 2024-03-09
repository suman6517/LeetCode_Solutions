class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int totalSum = 0;
        for(int i =0; i<nums.size(); i++)
        {
            totalSum = totalSum + nums[i];
        }

        int leftSum = 0;
        for(int j=0; j<nums.size(); j++)
        {
            if(2*leftSum + nums[j] == totalSum)
            {

                return j;

            }
            leftSum = leftSum + nums[j];
        }
        return -1;
    }
};