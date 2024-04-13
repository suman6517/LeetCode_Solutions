class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        vector <int>ans;

        int point1 =0;
        int point2 =0;

        int size1 = nums1.size(); 
        int size2= nums2.size();

        while (point1 <size1 && point2 <size2)
        {
            if (nums1[point1] == nums2[point2])
            {
                ans.push_back(nums1[point1]);

                while(point1 < size1-1 && nums1[point1] == nums1[point1+1])
                {
                    point1++;
                }

                while(point2 < size2-1 && nums2[point2] == nums2[point2+1])
                {
                    point2++;
                }

                point1++;
                point2++;

            }
            else if (nums1[point1] > nums2[point2])
            {
                point2++;
            }
            else
            {
                point1++;
            }
        }

        return ans;
    }
};