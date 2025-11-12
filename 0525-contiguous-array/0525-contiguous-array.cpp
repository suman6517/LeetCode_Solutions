class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        int length = nums.size();
        if(length == 0)
        {
            return 0;
        }
        for(int i=0; i<length; i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = -1;
            }
        }

        map<int,int>track;
        track.insert({0,-1});
        int sum =0;
        int maxSubArray =0;

        for(int i=0; i<length; i++)
        {
            sum = sum+nums[i];
            if(track.find(sum) != track.end())
            {
                maxSubArray = max(maxSubArray , i - track[sum]);
            }
            else
            {
                track.insert({sum,i});
            }
        }

        return maxSubArray;
    }
};