class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) 
    {
        if (arr.size() < k)
        {
            return "";
        }
        unordered_map<string , int >frequency;

        for(auto v : arr)
        {
            ++frequency[v];
        }
        for (auto v : arr)
        {
            if(frequency[v] == 1)
            {
                k--;
            }
            if(k == 0)
            {
                return v;
            }
        }
        return "";
    }
};