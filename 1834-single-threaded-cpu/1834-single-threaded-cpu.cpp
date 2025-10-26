class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
        vector<int>ans;
        int size = tasks.size();
        for(int i=0; i<size; i++)
        {
            tasks[i].push_back(i);
        }

        // Sort all the task On the basis of enque time 
        sort(tasks.begin(), tasks.end());

        long long timer = tasks[0][0];
        int i=0;

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;


        while(!pq.empty() || i<size)
        {
        // Put all the task in the minheap whose enque time is <= timer
        while(i < size && timer>=tasks[i][0])
        {
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }
        if(pq.empty())
        {
            timer = tasks[i][0];
        }
        else
        {
            ans.push_back(pq.top().second);
            timer+= pq.top().first;
            pq.pop();
        }
        }

        return ans;

    }
};