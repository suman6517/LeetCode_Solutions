class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int bestChoice = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size();i++)
        {
            int v1 = bestChoice + nums[i];
            int v2 = nums[i];

            bestChoice = max(v1 , v2);
            ans = max (bestChoice , ans);
        }

        return ans;
        
    }
};