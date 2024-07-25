class StockSpanner {
public:
stack<pair<int,int>>st;
int index = 0;
    StockSpanner() 
    {
        index = -1;
    }
    
    int next(int price) 
    {
        index +=1;
        while(!st.empty() && st.top().first <= price)
        {
            st.pop();
        }
        int pge =st.empty() ? -1 : st.top().second;

       int ans = index - pge ;
        st.push({price , index});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */