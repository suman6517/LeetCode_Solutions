class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<int>p;
        for(int i=0; i<gifts.size(); i++)
        {
            p.push(gifts[i]);
        }
        while(k!=0)
        {
            int highestElement = p.top();
            p.pop();
            int square = (int)sqrt(highestElement);
            p.push(square);
            k--;
        }
        long long  MaximumGift =0;
        while(!p.empty())
        {
            MaximumGift +=p.top();
            p.pop();
        }
        return MaximumGift;

    }
};