class Solution {
public:
    int maximumSum(vector<int>& arr) 
    {
        int ans = arr[0];

        int preOneDelete = INT_MIN;
        int preNoDelete = arr[0];

        for(int i = 1; i < arr.size(); i++)
        {
            int v1 = arr[i];

            int currOneDelete;

            if(preOneDelete == INT_MIN)
            {
                currOneDelete = preNoDelete;
            }
            else
            {
                currOneDelete = max(
                    preNoDelete,
                    preOneDelete + v1
                );
            }

            int currNoDelete = max(
                v1,
                preNoDelete + v1
            );

            preOneDelete = currOneDelete;
            preNoDelete = currNoDelete;

            ans = max(ans, max(preNoDelete, preOneDelete));
        }

        return ans;
    }
};