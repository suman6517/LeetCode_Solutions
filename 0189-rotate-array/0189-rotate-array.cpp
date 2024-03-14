class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> temp(size);

        for (int i = 0; i < size; i++) {
            int rotate_position = (i + k) % size;
            temp[rotate_position] = nums[i];
        }

        nums = temp;
    }
};