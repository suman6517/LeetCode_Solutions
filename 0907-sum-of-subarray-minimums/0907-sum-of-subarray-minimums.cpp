class Solution {
public:

vector<int> findNse(vector<int>arr)
{
    int n = arr.size();
    vector<int>nse(n);
    stack<int>st;
    for(int i = n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nse[i] = n;
        }
        else
        {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

vector<int> findPse(vector<int>arr)
{
    int n = arr.size();
    vector<int>pse(n);
    stack<int>st;

    for(int i = 0; i<n ; i++)
    {
        while(!st.empty() && arr[st.top()] >arr[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            pse[i] = st.top();
        }
        else
        {
            pse[i] = -1;
        }
        st.push(i);
    }
    return pse;
}

    int sumSubarrayMins(vector<int>& arr) 
    {
        int total = 0;
        const int mod = 1e9 +7;
        vector<int>nse = findNse(arr);
        vector<int>pse = findPse(arr);
        int size = arr.size();

       for(int i = 0; i<size; i++)
       {
        int left = i - pse[i];
        int right = nse[i] - i ;

        total = (total + (right * left * 1LL * arr[i])% mod) % mod;

       }
        return total;
    }
};