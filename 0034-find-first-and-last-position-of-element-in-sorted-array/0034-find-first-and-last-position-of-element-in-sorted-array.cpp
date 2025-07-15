class Solution {
public:

  int firstOccurance(vector<int>& nums, int target)
  {
    int start = 0;
    int end = nums.size()-1;
    int mid = start+(end -start)/2;
    int finalResult = -1;
    while(start <= end)
    {
        if(nums[mid] == target)
        {
            finalResult = mid;
            end = mid-1;
        }
        else if (nums[mid] > target)
        {
            end = mid -1;
        }
        else
        {
            start = mid +1;
        }
        mid = start+(end - start)/2;

    }
    return finalResult;
  }
  int secondOccurance(vector<int>& nums, int target)
  {
    int start = 0;
    int end = nums.size()-1;
    int mid = start+(end -start)/2;
    int finalResult = -1;
    while(start <= end)
    {
        if(nums[mid] == target)
        {
            finalResult = mid;
            start = mid+1;
        }
        else if (nums[mid] > target)
        {
            end = mid -1;
        }
        else
        {
            start = mid +1;
        }
        mid = start+(end - start)/2;

    }
    return finalResult;

  }
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        return {firstOccurance(nums , target) , secondOccurance(nums , target)};
    }
};