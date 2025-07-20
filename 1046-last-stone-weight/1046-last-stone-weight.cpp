class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        if(stones.size()==1)
        {
            return stones[0];
        }
        priority_queue<int>p;
        for(int i=0 ;i<stones.size(); i++)
        {
            p.push(stones[i]);
        }
        while (p.size() > 1)
        {
            int x = p.top();
            p.pop();
            int y = p.top();
            p.pop();
            if(x==y)
            {
                continue;
            }
            int remanning = x - y;
            p.push(remanning);
        }
        if(!p.empty())
        {
            return p.top();
        }
        return 0;

    }
};