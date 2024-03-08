class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        // vector<int>ans ;
        // int firstOccurance = firstPosition(nums,  target);
        // ans.push_back(firstOccurance);
        // int lastOccurance = lastPosition(nums,target);
        // ans.push_back(lastOccurance);
        // return ans;
        return { firstPosition(nums,  target) , lastPosition(nums,target)};

        
    }
    int firstPosition(vector<int>& nums, int target)
    {
        int start = 0;
        int end = nums.size()-1;
        int ans =-1;

        while(start <=end)
        {
            int mid =start+(end-start)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                end = mid -1;
            }
            else if (nums[mid] <target)
            {
                start = mid+1;
            }
            else
            {
                end = mid -1;
            }

           // mid = start+ (end-start) /2;

        }
        return ans ;
    }


    int lastPosition(vector<int>& nums, int target)
    {
        int start =0;
        int end = nums.size()-1;
       // int mid = start+ (end -start)/2;
        int ans = -1;
        while (start <= end )
        {
            int mid =start+(end-start)/2;
            if (nums[mid] == target)
            {
                ans = mid ;
                start = mid +1;

            }
            else if (nums [mid] <target)
            {
               start = mid+1;
            
            }
            else
            {
                end = mid -1;
            }
           // mid =  start + (end - start )/2;
        }
        return ans;
    }
};