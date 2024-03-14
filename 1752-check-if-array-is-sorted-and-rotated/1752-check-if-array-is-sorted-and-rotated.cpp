class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int n =  nums.size();
        int count = 0;

        for(int i =0 ; i<n ; i++)
        {
            int next_element = (i+1)%n;
            if (nums[i] > nums[next_element])
            {
                count ++;
            }
        }
        if (count <=1)
        {
            return true;
        }
        return false;
    }
};