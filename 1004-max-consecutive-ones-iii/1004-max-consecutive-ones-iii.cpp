class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int leftPointer= 0;
        int rightPointer = 0;
        int maxLength = 0;
        int zeroes = 0;
        int length = nums.size();

        while(rightPointer<length)
        {
            if(nums[rightPointer] == 0)
            {
                zeroes++;
            }
            while (zeroes > k)
            {
                if (nums[leftPointer] == 0)
                {
                    zeroes--;
                }
                leftPointer++;
            }
            // if(zeroes <= k)
            // {
                int length = rightPointer - leftPointer +1;
                 maxLength = max(length , maxLength);
            // }
            rightPointer++;
            
        }
        return maxLength;
        
    }
};