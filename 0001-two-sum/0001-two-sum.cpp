class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int , int>mpp;
        for (int i =0; i<nums.size() ; i++)
        {
            int compliment = target - nums[i];

            if (mpp.find(compliment) != mpp.end())
            {
                return { mpp[compliment] , i};
            }
            mpp.insert({nums[i] ,i});
        }
        return {};
        
    }
};