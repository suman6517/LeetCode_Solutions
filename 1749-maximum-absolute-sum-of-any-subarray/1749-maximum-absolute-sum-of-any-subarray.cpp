class Solution {
public:
int maxSum(vector<int>& nums)
{
    int ans = nums[0];
        int maxSum = nums[0];

        for(int i =1; i<nums.size(); i++)
        {
            int v1 = nums[i];
            int v2 =maxSum+v1;

            maxSum = max(v1,v2);

            ans = max(ans,maxSum);
        }
    return abs(ans);
}

int minSum(vector<int>& nums)
{
        int ans = nums[0];
        int minSum = nums[0];

        for(int i =1; i<nums.size(); i++)
        {
            int v1 = nums[i];
            int v2 =minSum+v1;

            minSum = min(v1,v2);

            ans = min(ans,minSum);
        }
        return abs(ans);

}
    
    int maxAbsoluteSum(vector<int>& nums) 
    {
        int minResult = minSum(nums);
        int maxResult = maxSum(nums);
        return max(minResult ,maxResult);

    }
};