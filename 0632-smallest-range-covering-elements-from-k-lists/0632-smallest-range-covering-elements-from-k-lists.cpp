class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {

        vector<int>ans(2);
        //Min Heap 
        priority_queue<pair<int,pair<int ,int>> , vector<pair<int,pair<int ,int>>> , greater<pair<int,pair<int ,int>>>>p;
        int minElement;
        int maxElement= INT_MIN;

        for(int i =0; i<nums.size(); i++)
        {
            p.push(make_pair(nums[i][0], make_pair(i,0)));
            maxElement= max(maxElement, nums[i][0]);
        }

        minElement = p.top().first;
        ans[0]= minElement;
        ans[1]= maxElement;

        pair<int,pair<int, int>>Element;
        int row, col , elem;
        while(p.size() == nums.size())
        {
            Element = p.top();
            p.pop();

            elem = Element.first;
            row = Element.second.first;
            col = Element.second.second;

            if(col+1 < nums[row].size())
            {
                col++;
                p.push(make_pair(nums[row][col] , make_pair(row, col)));
                maxElement= max(maxElement, nums[row][col]);
                minElement = p.top().first;

            } 

            if(maxElement - minElement < ans[1] - ans[0])
            {
                ans[0] = minElement;
                ans[1] = maxElement;

            }
            
        }

        return ans;



    }
};