class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int , vector<int>, greater<int>>p;

        for(int i =0; i<k; i++)
        {
            p.push(nums[i]);
        }
        while(k < nums.size())
        {
            int min_element = p.top(); 
            if(min_element < nums[k])
            {
                p.pop();
                p.push(nums[k]);
            }
            k++;
        }
        int Final_kTh_Element = p.top();
        return Final_kTh_Element;
    }
};