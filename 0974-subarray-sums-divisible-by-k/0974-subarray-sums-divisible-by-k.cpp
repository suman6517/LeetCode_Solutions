class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int , int>freq;
        freq[0] =1;
        int sum =0;
        int count =0;

        for(int it: nums)
        {

        sum+=it;

        int rem = sum % k;

        if(rem < 0)
        {
            rem += k;
        }

        if(freq.find(rem) != freq.end())
        {
            count += freq[rem];
        }

        freq[rem] ++;
    }
    return count;
    }
};