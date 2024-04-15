class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int ans [m+n];
        int i =0 , j =0;
        int k =0;

        while(i<m && j <n)
        {
            if (nums1[i] <nums2[j])
            {
                ans[k] = nums1[i];
                i++;
                k++;
            }
            else
            {
                ans [k++] = nums2[j++];
            }
            
        }
        while (i < m)
        {
            ans [k++] = nums1[i++];
        }
        while(j<n)
        {
            ans [k++] = nums2[j++];
        }

        for(int merge = 0; merge<k; merge++)
        {
            nums1[merge] = ans[merge];
        }

        
    }
};