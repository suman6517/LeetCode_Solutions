class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        // Max -Heap
        priority_queue<int>p;
        long long  sum = 0;

        for(int i=0;i<target.size(); i++)
        {
            p.push(target[i]);
            sum+=target[i];
        }
        int Max ;
        int rem;
        int elem;
        while(p.top() !=1)
        {
            Max = p.top();
            p.pop();
            rem = sum - Max;

            // Edge Case 
            if(rem <=0 || rem>=Max)
            {
                return 0;
            }
            elem = Max % rem;
            if(elem == 0 && rem!=1)
            {
                return 0;
            }
            
            sum = rem+elem;
            p.push(elem);
        }

        return 1;
    }
};