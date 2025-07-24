class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int rowSize = matrix.size();
        int colzSize = matrix[0].size();

        vector<pair<int , pair<int,int>>>temp;

        for(int i=0; i<rowSize; i++)
        {
            temp.push_back(make_pair(matrix[i][0] , make_pair(i , 0)));
        }

        priority_queue<
        pair<int , pair<int,int>>,
        vector<pair<int , pair<int ,int>>>,
        greater<pair<int , pair<int , int>>>
        >p(temp.begin() , temp.end());

        int ans = 0;
        pair<int,pair<int ,int>>element;
        while(k!=0)
        {
            element = p.top();
            ans = element.first;
            p.pop();
            int i = element.second.first;
            int j = element.second.second;

            // Push The Next Element If avalabale
            if(j+1 <colzSize)
            {
                p.push(make_pair(matrix[i][j+1], make_pair(i, j+1)));
            }

            k--;
            
        }

        return ans;


    }
};