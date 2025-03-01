class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int index = 0;
        for(int i =0; i<nums.size(); i++)
        {
            if (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                nums[i]= nums[i]*2;
                nums[i+1] = 0;
            }
            if(nums[i] !=0)
            {
                nums[index] = nums[i];

            if(i !=index )
            {
                nums[index] = nums[i];
                nums[i] = 0;
                
            }
            index++;
            }
           
            
        }
        return nums;
        
    }
};