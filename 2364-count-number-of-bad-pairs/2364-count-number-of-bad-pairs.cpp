class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        unordered_map<int , int>freq;
        int length = nums.size();
        long long goodPairs = 0;
        for(int i =0; i<length; i++)
        {
            int key = nums[i] -i;
            goodPairs += freq[key];
            freq[key]++;
        }
        // long long totalPairs = (length*(length-1))/2;
        // long long badPairs = totalPairs - goodPairs;
        // return badPairs;
        return (length*(length-1))/2 -goodPairs;
    }
};