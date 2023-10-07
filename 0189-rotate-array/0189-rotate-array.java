class Solution {
    public void rotate(int[] nums, int k) 
    {
         int arrayLength = nums.length;
        int temp [] =  new int [arrayLength];

        for (int i =0 ; i<arrayLength; i++)
        {
             temp[(i+k)%arrayLength] = nums[i];
        }

        for(int i=0; i<nums.length; i++){
            nums[i]= temp[i];
            }
        
    }
}