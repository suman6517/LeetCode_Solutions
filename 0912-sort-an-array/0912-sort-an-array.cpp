class Solution {
public:

void merge(vector<int>& nums , int low , int mid , int high )
{
    int size = nums.size();
    vector<int>temp;

    int leftPtr = low;
    int rightPtr = mid+1;

    while(leftPtr <= mid && rightPtr<=high)
    {
        if(nums[leftPtr] <= nums[rightPtr])
        {
            temp.push_back(nums[leftPtr]);
            leftPtr++;
        }
        else
        {
            temp.push_back(nums[rightPtr]);
            rightPtr ++;
        }
    }
    while(leftPtr <= mid)
    {
        temp.push_back(nums[leftPtr]);
        leftPtr++;
    }
    while(rightPtr <= high)
    {
        temp.push_back(nums[rightPtr]);
        rightPtr ++;
    }

     for (int i = low; i <= high; i++) 
     {
        nums[i] = temp[i - low];
     }
}

void mergeSort(vector<int>& nums , int low , int high)
{
    if(low >= high)
    {
        return ;
    }
    int mid = low + (high - low) /2;
    mergeSort(nums , low , mid);
    mergeSort(nums , mid+1, high);

    merge(nums , low , mid , high);
}
    vector<int> sortArray(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size() -1 ;
        mergeSort(nums , low , high);
        return nums;
    }
};