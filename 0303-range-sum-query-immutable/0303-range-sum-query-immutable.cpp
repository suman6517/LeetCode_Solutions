class NumArray {
public:
vector<int>preArray;
    NumArray(vector<int>& nums) 
    {
        preArray = nums;
        for(int i =1; i<nums.size();i++)
        {
            preArray[i]+=preArray[i -1];
        }
    }
    
    int sumRange(int left, int right) 
    {
        if(left ==0 )
        {
            return preArray[right];
        }
        return preArray[right] - preArray[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */