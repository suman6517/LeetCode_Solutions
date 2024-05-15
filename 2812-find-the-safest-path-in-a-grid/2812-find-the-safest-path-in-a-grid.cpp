class Solution {
public:
    int sF = 0;
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int rw = grid.size(), cw = grid[0].size();
        vector<vector<int>> dG(rw, vector<int>(cw, INT_MAX));
        if(grid[0][0] == 1)dG[0][0] = 0;
        // up to bottom
        for(int r = 0; r < rw; r++){
            for(int c = 0; c < cw; c++){
                if(r == 0 && c== 0)continue;
                if(grid[r][c] == 1){
                    dG[r][c] = 0;
                    continue;
                }
                int minD = min(r > 0 ? dG[r-1][c] : INT_MAX, c > 0 ? dG[r][c-1] : INT_MAX);
                if(minD != INT_MAX)
                 dG[r][c] = minD + 1; 
            }
        }
        // for(auto & vc : dG){
        //     for(auto v : vc){
        //         cout<<v<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        if(grid[rw-1][cw-1] == 1)dG[rw-1][cw - 1] = 0;
        //down to up
        for(int r = rw-1; r > -1; r--){
            for(int c = cw - 1; c > -1; c--){
                if(r == rw-1 && c == cw - 1){
                    continue;
                }
                if(grid[r][c] == 1){
                    dG[r][c] = 0;
                    continue;
                }
                int minD = min((r < rw-1) ?  dG[r+1][c] : INT_MAX, (c < cw-1) ? dG[r][c+1] : INT_MAX);
                if(minD != INT_MAX)
                    dG[r][c] = min(dG[r][c], 1 + minD);
            }
        }
        // for(auto & vc : dG){
        //     for(auto v : vc){
        //         cout<<v<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return findSf(dG, rw, cw);      
    }
private:
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int findSf(vector<vector<int>> & dG, int r, int c){
        int left = 0, right = 1e9;
        int maxSafe = 0;
        while(left <= right){
           int testSf = left + (right - left)/2;
           if(test(dG, testSf)){
               maxSafe = testSf;
               left = testSf + 1;
           }else{
               right = testSf - 1;
           }
        }
        return maxSafe; 
    }
    bool test(vector<vector<int>>&dG, int testSf) 
    {
        int sz = dG.size();
        queue<pair<int, int>>que;
        vector<vector<bool>>visited(sz, vector<bool>(sz, false));
        if (dG[0][0] < testSf) return false;
        que.push({0, 0});
        visited[0][0] = true;
        while(!que.empty())
        {
            auto cords = que.front();
            que.pop();
            int currRow = cords.first, currCol = cords.second;
            if (currRow == sz - 1 && currCol == sz - 1) return true;
            for (auto dir : dirs)
            {
                int newRow = currRow + dir[0];
                int newCol = currCol + dir[1];
                if (checkCord(visited, newRow, newCol))
                {
                    if (dG[newRow][newCol] < testSf) continue;
                    visited[newRow][newCol] = true;
                    que.push({newRow, newCol});
                }
            }
        }
        return false;
    }
    bool checkCord(vector<vector<bool>>&visited, int r, int c)
    {
        int cols = visited[0].size(), rows = cols;
        return !(r < 0 || c < 0 || r == rows ||  c == cols || visited[r][c] == 1);
    }
    
};