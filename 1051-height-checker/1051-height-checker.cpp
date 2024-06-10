class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // counting sort variant 
        int freq[101]={0};
        for(int x: heights) freq[x]++;
        int cnt=0;
        for (int x=1; x<=100; x++){
            int f=freq[x];
            for(int i=cnt; i<cnt+f; i++)
                heights[i]-=x;
            cnt+=f;
        }
        //Use count 0's
        return heights.size()-count(heights.begin(), heights.end(), 0);
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();