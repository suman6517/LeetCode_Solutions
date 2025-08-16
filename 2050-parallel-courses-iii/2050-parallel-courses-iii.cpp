class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        // Create Adj List 
        vector<vector<int>> adjList(n);
        for(auto it:relations)
        {

            // Convert them o base Index
            adjList[it[0] - 1].push_back(it[1] - 1);
        }

        vector<int> InDeg(n, 0);
        for(int i =0; i<n; i++)
        {
            for(int j=0; j<adjList[i].size(); j++)
            {
                InDeg[adjList[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++)
        {
            if(InDeg[i] == 0)
            {
                q.push(i);
            }
        }
        // maximum Time To Complete The Previous Course
        vector<int>coursePreTime(n,0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:adjList[node])
            {
                InDeg[it] --;
                if(InDeg[it] ==0)
                {
                    q.push(it);
                }
                // MaximumTime to complete the previous Course and the current course
                // coursePreTime[it] = max(coursePreTime[it],coursePreTime[it] +time[node]);
                coursePreTime[it] = max(coursePreTime[it], coursePreTime[node] + time[node]);

            }
        }
        int ans =0;
        for(int i =0; i<n; i++)
        {
           ans = max(ans, coursePreTime[i] + time[i]);
        }
        return ans;
    }
};