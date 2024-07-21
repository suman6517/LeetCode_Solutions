class Solution {
public:
    int trap(vector<int>& height) 
    {
         int size = height.size() - 1;
         int leftMax = 0, rightMax = 0, leftPtr = 0, total = 0;
         int rightPtr = size;


        while(leftPtr < rightPtr)
        {
            if(height[leftPtr] <= height[rightPtr])
            {
                if(leftMax > height[leftPtr])
                {
                    total += leftMax - height[leftPtr];
                }
                else
                {
                    leftMax = height[leftPtr];
                }
                leftPtr ++;        
            }
            else
            {
                  if(rightMax > height[rightPtr])
                {
                    total += rightMax - height[rightPtr];

                }
                else
                {
                    rightMax = height[rightPtr];
                    
                }
                rightPtr --;       

            }
        }
        return total;
    }
};