class Solution {
public:
int minSum(vector<int>& nums)
{
    int totalAbs = nums[0];
    int minSum = nums[0];
    int tillBest = nums[0];

    for(int i=1; i< nums.size(); i++)
    {
        totalAbs = totalAbs + nums[i];
        int v1 = nums[i];
        int v2 = tillBest + v1;

        tillBest = min(v1 , v2);
        minSum = min(minSum , tillBest);
    }

    int ans = totalAbs - minSum;
    return ans;

}

int maxSum(vector<int>& nums)
{
    int ans = nums[0];
    int tillBest = nums[0];

    for(int i=1; i< nums.size(); i++)
    {
        int v1 = nums[i];
        int v2 = tillBest + v1;

        tillBest = max(v1 , v2);
        ans = max(ans , tillBest);
    }

    return ans;
}
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int minimum = minSum(nums);
        int maximum = maxSum(nums);

        if(maximum < 0)
        {
            return maximum;
        }

        int ans = max(minimum,maximum);

        return ans;
    }
};