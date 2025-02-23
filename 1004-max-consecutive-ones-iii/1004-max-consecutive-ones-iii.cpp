class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int leftPointer= 0;
        int rightPointer = 0;
        int maxLength = 0;
        int zeroes = 0;
        int length = nums.size();

        while (rightPointer < length)
        {
            if (nums[rightPointer] == 0)
                zeroes++;

            if (zeroes > k)
            {
                if (nums[leftPointer] == 0)
                    zeroes--;
                leftPointer++;
            }

            // Directly update maxLength without redundant check
            maxLength = max(maxLength, rightPointer - leftPointer + 1);

            rightPointer++;
        }

        return maxLength;
        
    }
};