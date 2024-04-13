class Solution {
public:

    bool binarySearch(vector<int>& nums1 ,int target)
    {
        int start = 0;
        int end =nums1.size()-1;
        while(start <= end)
        {
            int mid = start+ (end - start)/2;

            if (nums1[mid] == target)
            {
                return true;
            }
            else if (nums1[mid] > target)
            {
                end = mid -1;
            }
            else
            {
                start = mid +1;
            }
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin() , nums1.end());
        unordered_set<int>preAns;

        for(auto it: nums2)
        {
            if(binarySearch(nums1 , it))
            {
                preAns.insert(it);
            }
        }

        vector <int>ans(preAns.begin() , preAns.end());

        return ans;
    }
};